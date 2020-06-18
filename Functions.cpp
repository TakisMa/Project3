#include <iostream>
#include <sstream>
//#include <string>
#include <cstring>
#include <cstdlib>
#include <netdb.h>
#include "Functions.h"

using namespace std;

bool check_int(char *num) { //checks if num is a number
    int i=0;
    do{
        if(num[i]<'0' || num[i]>'9') return false;
        i++;
    }while(num[i]!='\0');
    return true;
}

int checkClientArguments(int argc, char **argv, char *&filepath, int &threadNum, int &servPort, hostent *servIP) {
    bool arP = false;
    bool arH1 = false;
    bool arH2 = false;
    bool arB = false;

    if(argc != 9) {
        cout << "Wrong arguments!" << endl;
        return -1;
    }
    else {
        for(int i = 1; i < argc; i += 2 ) {
            if((strcmp("-q", argv[i]) == 0) && !arP){
                if(i + 1 < 9){
                    filepath = new char[strlen(argv[i+1])];
                    strcpy(filepath, (argv[i+1]));
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-sp", argv[i]) == 0) && !arH1){
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -h1 is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        servPort = atoi(argv[i+1]);
                        arH1 = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-w", argv[i]) == 0) && !arH2) {
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -h2 is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        threadNum = atoi(argv[i+1]);
                        arH2 = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-sip", argv[i]) == 0) && !arB) {
                if(i + 1 < 9){
                    servIP = gethostbyname(argv[i+1]);
                    arB = true;

                    /*if(!check_int(argv[i+1])) {
                        cout << "Argument after -b is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        servIP = atoi(argv[i+1]);
                    }*/
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
        }
        if(!arB || !arH1 || !arH2 || !arB) {
            cout << "Wrong arguments!" << endl;
            return -1;
        }
        else if(servIP == 0 || servPort == 0 || threadNum == 0){
            cout << "Wrong initialization parameters " << endl;
            return -2;
        }
    }
    return 0;
}

int checkServerArguments(int argc, char **argv, int &query, int &stat, int &threadNum, int &bufferSize) {
    bool arP = false;
    bool arH1 = false;
    bool arH2 = false;
    bool arB = false;

    if(argc != 9) {
        cout << "Wrong arguments!" << endl;
        return -1;
    }
    else {
        for(int i = 1; i < argc; i += 2 ) {
            if((strcmp("-q", argv[i]) == 0) && !arP){
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -h1 is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        query = atoi(argv[i+1]);
                        arH1 = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-s", argv[i]) == 0) && !arH1){
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -h1 is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        stat = atoi(argv[i+1]);
                        arH1 = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-w", argv[i]) == 0) && !arH2) {
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -h2 is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        threadNum = atoi(argv[i+1]);
                        arH2 = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
            else if((strcmp("-b", argv[i]) == 0) && !arB) {
                if(i + 1 < 9){
                    if(!check_int(argv[i+1])) {
                        cout << "Argument after -b is not an INT!" << endl;
                        return -3;
                    }
                    else {
                        bufferSize = atoi(argv[i+1]);
                        arB = true;
                    }
                }
                else {
                    cout << "Wrong arguments!" << endl;
                    return -1;
                }
            }
        }
        if(!arB || !arH1 || !arH2 || !arB) {
            cout << "Wrong arguments!" << endl;
            return -1;
        }
        else if(query == 0 || stat == 0 || threadNum == 0 || bufferSize == 0){
            cout << "Wrong initialization parameters " << endl;
            return -2;
        }
    }
    return 0;
}

string getWord(string str) {
    string word;
    stringstream iss(str);

    iss >> word;
    return word;
}


