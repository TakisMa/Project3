#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include "../Functions.h"
#include "client_utility.h"
#include <string>
#include <cstring>

#define MAX_SIZE 10

using namespace std;

int main(int argc, char *argv[]) {
    int numThreads, servPort;
    hostent *servIP;
    string queryFile;

    if(checkClientArguments(argc, argv, queryFile, numThreads, servPort, servIP) < 0) {
        perror("initialization");
    }

    int sock_desc;
    struct sockaddr_in serv_addr;
    char sbuff[MAX_SIZE],rbuff[MAX_SIZE];

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Failed creating socket\n");

    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(3000);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    while(true) {
        printf("Connected successfully - Please enter string\n");
        if(strcmp(sbuff, "end") == 0) break;
        while (fgets(sbuff, MAX_SIZE, stdin) != NULL) {
            send(sock_desc, sbuff, strlen(sbuff), 0);
/*
            if (recv(sock_desc, rbuff, MAX_SIZE, 0) == 0)
                printf("Error");
            else
                fputs(rbuff, stdout);

            bzero(rbuff, MAX_SIZE);//to clean buffer-->IMP otherwise previous word characters also came
            printf("Received %s from server\n", rbuff);*/
        }
    }

    close(sock_desc);
     return 0;
}