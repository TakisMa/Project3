#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>
#include <string>
#include <sstream>
#include "Functions.h"
#include "SummaryManagement.h"
#include "SignalHandling.h"
#include "FileManagement.h"

#define BUCKETS_NUM 10
using namespace std;

int main(int argc, char *argv[]) {
    /* Check arguments */
    int numWorkers, bufferSize, serverPort;
    char *servIP;
    string filePath;
    if(checkArguments(argc, argv, numWorkers, bufferSize, serverPort, servIP, filePath ) != 0) {
        return -10;
    }

    struct sigaction child_act;
    sigemptyset(&child_act.sa_mask);
    child_act.sa_flags = SA_SIGINFO | SA_RESTART;
    child_act.sa_sigaction = child_int;
    if(sigaction(SIGCHLD, &child_act, NULL) == - 1) cout << "Error with sigaction: " << errno << endl;
    signal(SIGPIPE, SIG_IGN);
    signals = -1;

    int wstatus;
    string w;
    pid_t *childpid = new pid_t[numWorkers];
    DIR * dirp;
    struct dirent * entry;
    int lastElement;
    char *readbuf;
    char *writebuf;
    char **myfifo = new char*[numWorkers];
    char **auxfifo = new char*[numWorkers];
    int *fd = new int[numWorkers];
    int *fd2 = new int[numWorkers];

    WHashtable *workerM = new WHashtable(BUCKETS_NUM);

    /* Determine number of directories */
    const char *cfilepath = filePath.c_str();
    dirp = opendir(cfilepath);
    if(!dirp) {
        cout << "Failed to open directory" << endl;
        return errno;
    }


    /* Create/execute children process equal to numWorkers and store pids in childpid array */
    char program[]="./../cmake-build-debug/Worker";

    int digits = findDigits(bufferSize);
    char *bufferArg = new char[digits+1];
    sprintf(bufferArg, "%d", bufferSize);

    digits = findDigits(serverPort);
    char *sPortArg = new char[digits+1];
    sprintf(sPortArg, "%d", serverPort);

    char *argumentsv[] = {program, bufferArg, sPortArg, servIP, NULL};
    for(int i = 0; i < numWorkers; i++) {
        childpid[i] = fork();
        if(childpid[i] < 0) {
            cout << "Fork Failed" << endl;
            return errno;
        }
        else if(childpid[i] > 0) {
            myfifo[i] = create_fifo("myfifo", childpid[i]);
            if(mkfifo(myfifo[i], 0666) == -1 && errno != EEXIST) {
                cout << "Error with main myfifo: " << errno << endl;
            }
            fd[i] = open(myfifo[i], O_WRONLY);

            auxfifo[i] = create_fifo("auxfifo", childpid[i]);
            if(mkfifo(auxfifo[i], 0666) == -1 && errno != EEXIST) {
                cout << "Error with main auxfifo: " << errno << endl;
            }
            fd2[i] = open(auxfifo[i], O_RDONLY);

        }
        if(childpid[i] == 0) {
            if(execvp("./../cmake-build-debug/Worker", argumentsv) == -1) {
                cout << "Exec failed " << endl;
                return errno;
            }
        }
    }
//    delete [] bufferArg;
    /*for(int i = 0; i< numWorkers; i++) {
        read_line(fd2[i], readbuf, bufferSize);
        delete [] readbuf;
    }*/
    
    if((dirp = opendir(cfilepath)) != NULL) {
        int pos = 0;
        while ((entry = readdir(dirp)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0) {
                    workerM->insertSummary(entry->d_name, fd[pos], fd2[pos], childpid[pos]);

                    /* send path to child process */
                    char *tosend = new char[strlen(cfilepath) + strlen(entry->d_name) + 2];
                    sprintf(tosend, "%s/%s", cfilepath, entry->d_name);
                    write_line(fd[pos], writebuf, bufferSize, tosend);
                    delete[] tosend;
                    delete [] writebuf;

                    /* read & print summary statics */
                    read_line(fd2[pos], readbuf, bufferSize);
                    char *c = new char[strlen(readbuf) + 1];
                    strcpy(c, readbuf);
                    c[strlen(readbuf)] = '\0';
                    print_summary(c);

                    delete [] c;
                    delete[] readbuf;
                    if(pos == numWorkers - 1) pos = 0;
                    else pos++;
            }
        }
        cout << endl;
        lastElement = pos;
        closedir(dirp);
    }
    for(int i = 0; i < numWorkers; i++) {
        write_line(fd[i], writebuf, bufferSize, "OK");
        delete [] writebuf;
    }
    int pos = 0;

    while(true) {
        read_line(fd2[pos], readbuf, bufferSize);
        if ((strcmp(readbuf, "OK") == 0) && pos == numWorkers-1) {
            delete [] readbuf;
            break;
        }
        else if ((strcmp(readbuf, "OK") == 0)) pos++;
        delete [] readbuf;
    }

    while(true) {
        if(signals > 0) {
            char *tmp = new char[workerM->getAllCountries(signals).length() + 1];
            strcpy(tmp, workerM->getAllCountries(signals).c_str());
            tmp[workerM->getAllCountries(signals).length()] = '\0';
            char *country_token = strtok(tmp, "?");
            int child_pos = -1;
            for(int i = 0; i < numWorkers; i++){
                if(childpid[i] == signals){
                    child_pos = i;
                    break;
                }
            }
            if(child_pos < 0) {
                cout << "ERROR finding killed process " << endl;
                exit(5);
            }
            unlink(myfifo[child_pos]);
            unlink(auxfifo[child_pos]);
            
            childpid[child_pos] = fork();
            if(childpid[child_pos] < 0) {
                cout << "Fork Failed" << endl;
                return errno;
            }
            else if(childpid[child_pos] > 0) {
                myfifo[child_pos] = create_fifo("myfifo", childpid[child_pos]);
                if(mkfifo(myfifo[child_pos], 0666) == -1 && errno != EEXIST) {
                    cout << "Error with main myfifo: " << errno << endl;
                }
                fd[child_pos] = open(myfifo[child_pos], O_WRONLY);

                auxfifo[child_pos] = create_fifo("auxfifo", childpid[child_pos]);
                if(mkfifo(auxfifo[child_pos], 0666) == -1 && errno != EEXIST) {
                    cout << "Error with main auxfifo: " << errno << endl;
                }
                fd2[child_pos] = open(auxfifo[child_pos], O_RDONLY);

            }
            if(childpid[child_pos] == 0) {
                if(execvp("./cmake-build-debug/worker", argumentsv) == -1) {
                    cout << "Exec failed " << endl;
                    return errno;
                }
            }

            while(true) {
                cout << country_token << endl;
                workerM->insertSummary(country_token, fd[child_pos], fd2[child_pos], childpid[child_pos]);

                /* send path to child process */
                char *tosend = new char[strlen(cfilepath) + strlen(country_token) + 2];
                sprintf(tosend, "%s/%s", cfilepath, country_token);
                write_line(fd[child_pos], writebuf, bufferSize, tosend);
                cout << "writebuf: " << writebuf << endl;
                delete[] tosend;
                delete [] writebuf;

                /* read & print summary statics */
                cout << "fd/fd2/pid/pos/country: " << fd[child_pos] << " " << fd2[child_pos] << " " << childpid[child_pos] << " " << pos << " " << country_token << endl;
                read_line(fd2[child_pos], readbuf, bufferSize);
                char *c = new char[strlen(readbuf) + 1];
                strcpy(c, readbuf);
                c[strlen(readbuf)] = '\0';
//                    print_summary(c);

                country_token = strtok(NULL, "?");
                if(!country_token) break;
            }
            write_line(fd[child_pos], writebuf, bufferSize, "OK");
            delete [] writebuf;
            cout << endl;

            while(true) {
                read_line(fd2[child_pos], readbuf, bufferSize);
                if (strcmp(readbuf, "OK") == 0) break;
            }
            delete [] writebuf;
            delete [] readbuf;
            signals = -1;
        }

        cout << "Enter command: " << endl;
        if (!getline(cin, w)) {
            cout<<"w: " << w<<endl;
            cout << "ERROR: " << errno << endl;
            continue;
        }
        stringstream iss(w);
        string word;
        iss >> word;
        if(!w.empty()){
            if(w == "/exit") {
                for(int i = 0; i < numWorkers; i++){
                    close(fd[i]);
                    unlink(myfifo[i]);

                    close(fd2[i]);
                    unlink(auxfifo[i]);
                    delete[] myfifo[i];
                    delete[] auxfifo[i];
                    kill(childpid[i], SIGKILL);
                    cout << "killed child: " << childpid[i] << endl;
                }
                delete [] myfifo;
                delete [] auxfifo;
                delete [] fd;
                delete [] fd2;
                delete [] childpid;
                delete workerM;
                break;
            }
            else if(word == "/topk-AgeRanges") {
                fflush(stdout);
                int identifier;
                char *m = new char[w.length() +1];
                strcpy(m, w.c_str());
                m[w.length()] = '\0';
                string virus, country, date1, date2;
                int k;
                iss >> k;
                cout << "k = " << k << endl;
                if(k > 4) continue;
                iss >> country;
                iss >> virus;
                iss >> date1;
                iss >> date2;
                write_line(workerM->writeFD(country), writebuf, bufferSize, m);
                for(int i = 0; i < k; i++){
                    read(workerM->readFD(country), &identifier, sizeof(int));
                    if(identifier < 0) break;
                    cout << "identifier = " << identifier << endl;
                }
            }
            else if(word == "/listCountries" || word == "/searchPatientRecord"){
                int identifier;
                char *m = new char[w.length() +1];
                strcpy(m, w.c_str());
                m[w.length()] = '\0';
                for(int i = 0; i < numWorkers; i++) {
                    write_line(fd[i], writebuf, bufferSize, m);
                    delete [] writebuf;
                }
                delete [] m;
                int *noCountries = new int[numWorkers];
                for(int i = 0; i < numWorkers; i++) {
                    read(fd2[i], &noCountries[i], sizeof(int));
                }
                for(int i = 0; i < numWorkers; i++) {
                    for(int j = 0; j < noCountries[i]; j++) {
                        read_line(fd2[i], readbuf, bufferSize);
                        cout << readbuf << endl;
                        delete[] readbuf;
                    }
                }
            }
            else if(word == "/numPatientAdmissions" || word == "/numPatientDischarges") {
                char *m = new char[w.length()+1];
                strcpy(m, w.c_str());
                string virus, date1, date2, country, com;
                stringstream iss(w);
                iss >> com;
                iss >> virus;
                iss >> date1;
                iss >> date2;
                iss >> country;
                if(country.empty()) {
                    /* write command to all processes */
                    for(int i = 0; i < numWorkers; i++) {
                        write_line(fd[i], writebuf, bufferSize, m);
                        delete [] writebuf;
                    }
                    delete [] m;


                    /* read & print results from all processes */
                    int *noCountries = new int[numWorkers];
                    for(int i = 0; i < numWorkers; i++) read(fd2[i], &noCountries[i], sizeof(int));
                    for(int j = 0; j < numWorkers; j++){
                        for(int i = 0; i < noCountries[j]; i++){
                            read_line(fd2[j], readbuf, bufferSize);
                            cout << readbuf << endl;
                            delete [] readbuf;
                        }
                    }
                    delete [] noCountries;
                }
                else {
                    /* write command to pipe */
                    write_line(workerM->writeFD(country), writebuf, bufferSize, m);
                    delete [] writebuf;
                    delete [] m;

                    /* read & print result */
                    read_line(workerM->readFD(country), readbuf, bufferSize);
                    cout << readbuf << endl;
                    delete [] readbuf;
                }
            }
            else if(word == "/diseaseFrequency"){
                string virus, date1, date2, country;
                int identifier, total = 0;
                iss >> virus;
                iss >> date1;
                iss >> date2;
                iss >> country;
                char *m = new char[w.length() +1];
                strcpy(m, w.c_str());
                m[w.length()] = '\0';
                if(country.empty()) {
                    for(int i = 0; i < numWorkers; i++) {
                        write_line(fd[i], writebuf, bufferSize, m);
                        delete [] writebuf;
                    }
                    delete [] m;
                    for(int i = 0; i < numWorkers; i++) {
                        read(fd2[i], &identifier, sizeof(int));
                        if(identifier < 0) continue;
                        else total += identifier;
                    }
                    cout << total << endl;
                }
                else {
                    write_line(workerM->writeFD(country), writebuf, bufferSize, m);
                    read_line(workerM->readFD(country), readbuf, bufferSize);
                    cout << readbuf << endl;
                    delete [] m;
                    delete [] writebuf;
                    delete [] readbuf;
                }
            }
            else continue;
        }
        else continue;
    }

    wait(&wstatus);

    return 0;
}

