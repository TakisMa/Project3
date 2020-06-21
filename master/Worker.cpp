#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <dirent.h>
#include <sstream>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Tree.h"
#include "Bucket.h"
#include "Hashtable.h"
#include "Heap.h"
#include "RecordIDManagement.h"
#include "Functions.h"
#include "Record.h"
#include "Commands.h"
#include "SignalHandling.h"

#define SIZE 10
#define BUCKET_NUM 100
#define BUCKET_SIZE 1024


int main(int argc, char* argv[]) {
    struct sigaction act;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = kill_child;
    act.sa_flags = SA_SIGINFO;
    if(sigaction(SIGQUIT, &act, NULL) == -1) cout << "Error with child sigaciton: " << errno << endl;
    if(sigaction(SIGINT, &act, NULL) == -1) cout << "Error with child sigaciton: " << errno << endl;

    struct sigaction act_newFile;
    sigemptyset(&act_newFile.sa_mask);
    act_newFile.sa_sigaction = new_file;
    if(sigaction(SIGUSR1, &act_newFile, NULL) == -1) cout << "Error with child sigaciton: " << errno << endl;


    signals = 0;
    int bufferSize = atoi(argv[1]);
    int serverPort = atoi(argv[2]);
    char *serverIP = new char[strlen(argv[3])];
    strcpy(serverIP, argv[3]);
    int offset = atoi(argv[4]);
    int sock_desc;
    struct sockaddr_in serv_addr;
    struct sockaddr_in my_sock;
    struct sockaddr_in client;
    struct sockaddr *mysock_ptr=(struct sockaddr *)&my_sock;
    socklen_t clientlen;

    int fd , fd2, sent;
    string filePath, word, i, j, k;
    char *filepath;
    string w, countryS;
    char *readbuf, *writebuf;
    char *myfifo, *auxfifo;
    int success = 0, fail = 0;
    char sbuf[1024], rbuf[1024];


    /* Setup connection to server */
    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed creating socket\n");
    }
    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serverIP);
    //serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(serverPort);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server\n");
    }
    sprintf(sbuf, "%d", serverPort+offset);
    write(sock_desc, sbuf, sizeof(sbuf));
    cout << "workerPort: " << sbuf <<endl;

    /* End of setup connection */




    ID_Hashtable *idHT = new ID_Hashtable(SIZE);
    Hashtable *diseaseHT = new Hashtable(BUCKET_NUM, BUCKET_SIZE, disease);
    Hashtable *countryHT = new Hashtable(BUCKET_NUM, BUCKET_SIZE, country);

    myfifo = create_fifo("myfifo", getpid());
    auxfifo = create_fifo("auxfifo", getpid());

    if (mkfifo(myfifo, 0666) == -1 && errno != EEXIST) {
        cout << "Error with main mkfifo: " << errno << endl;
        return errno;
    }
    fd = open(myfifo, O_RDONLY);
    if(fd == -1) cout << "error with fd: " << myfifo << endl;


    if (mkfifo(auxfifo, 0666) == -1 && errno != EEXIST) {
        cout << "Error with main auxfifo: " << errno << endl;
    }
    fd2 = open(auxfifo, O_WRONLY);
    if(fd2 == -1) cout << "error with fd2: " << auxfifo << endl;

    while (true) {
        if(read_line(fd, readbuf, bufferSize) != 0) {
            cout << "error in read" << endl;
            fail++;
            return errno;
        }
        if (strcmp(readbuf, "OK") == 0) {
            delete [] readbuf;
            break;
        }
        else {
            filepath = new char[strlen(readbuf)+1];
            strcpy(filepath, readbuf);
            filepath[strlen(readbuf)] = '\0';
            char *c = strtok(readbuf, "/");
            c = strtok(NULL, "/");
            char *country=new char[strlen(c)+1];
            strcpy(country,c);
            initialize_record(filepath, country, diseaseHT, countryHT, idHT, fd2, sock_desc, bufferSize);
            delete [] country;
        }
        delete [] readbuf;
    }
    write_line(fd2, writebuf, bufferSize, "OK");
    delete [] writebuf;
    close(fd2);
    close(fd);
    unlink(myfifo);
    unlink(auxfifo);


    /* Setting up sockets for server communication */
//    socket_setup(fd2, serverPort, serverIP, &serv_addr);



    clientlen = sizeof(client);
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("Query socket");
    my_sock.sin_family = AF_INET;  /*Internet domain */
    my_sock.sin_addr.s_addr = htonl(INADDR_ANY);
    my_sock.sin_port = htons(serverPort+offset);  /*The given port*/
    if(bind(fd, mysock_ptr, sizeof(my_sock)) < 0) perror("worker bind");
    if(listen(fd, 10) < 0) perror("worker listen");
    if(accept(fd, (struct sockaddr *) &client, &clientlen) < 0) perror("worker accept");
    read(fd, rbuf, sizeof(rbuf));
    cout << "worker read from server: " << rbuf << endl;
    strcpy(sbuf, "hi from worker");
    write(sock_desc, sbuf, sizeof(sbuf));
    while(1);

    while(signals != SIGINT){
        /*Error & signal handling */
        if(signals == SIGUSR1) {
            string countries = countryHT->getCountry().c_str();
            char *c = new char[countries.length() + 1];
            strcpy(c, countries.c_str());
            c[countries.length()] = '\0';
            char *countriesC = strtok(c, "?");
            while(countriesC != NULL) {
                initialize_record(filepath, countriesC, diseaseHT, countryHT, idHT, fd2, sock_desc, bufferSize);
                countriesC = strtok(NULL, "?");
            }
            delete [] c;
            signals = -1;
        }
        int size = 0;

         /*Waiting for server to issue command */

         read(fd, &size, sizeof(int));
         if (read_line(fd, readbuf, size, bufferSize) != 0) {
            cout << "error in read" << endl;
            fail++;
            return errno;
         }
         string g(readbuf);
         delete [] readbuf;
         int tmp = select_command(diseaseHT, countryHT, idHT, filepath, g, fd2, bufferSize);
         if(tmp > 0) success++;
         else fail++;
    }
    delete diseaseHT;
    delete countryHT;
    delete idHT;
    kill(getpid(), SIGKILL);
    return 0;
}