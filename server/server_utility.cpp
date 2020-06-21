#include "server_utility.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>

#define BACKLOG 10

using namespace std;

void perror_exit(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int socket_setup(struct sockaddr_in *serverQ, struct sockaddr_in *serverS, struct sockaddr *serverQ_ptr,
                 struct sockaddr *serverS_ptr, int &sockQ, int &sockS, int &queryPort, int &statisticsPort) {
    /* Create socket */
    if ((sockQ = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror_exit("Query socket");
    serverQ->sin_family = AF_INET; /* Internet domain */
    serverQ->sin_addr.s_addr = htonl(INADDR_ANY);
    serverQ->sin_port = htons(queryPort); /* The given port */

    if ((sockS = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror_exit("Statistics socket");
    serverS->sin_family = AF_INET; /* Internet domain */
    serverS->sin_addr.s_addr = htonl(INADDR_ANY);
    serverS->sin_port = htons(statisticsPort); /* The given port */

/* Bind socket to address */
    if (bind(sockQ, serverQ_ptr, sizeof(*serverQ)) < 0)
        perror_exit("Query bind");

    if (bind(sockS, serverS_ptr, sizeof(*serverS)) < 0)
        perror_exit("Statistics bind");
/* Listen for connections */
    if (listen(sockQ, BACKLOG) < 0) perror_exit("Query listen");
    if (listen(sockS, BACKLOG) < 0) perror_exit("Statistics listen");

    return 0;
}

void print_summary(char *sum) {
    char *summary;
    summary = strtok(sum, "?");
    while(summary) {
        if(summary[0] == '\\'){
            summary++;
            cout << "Age range 0-20 years: " << summary << " cases" << endl;
            summary = strtok(NULL, "?");
            cout << "Age range 21-40 years: " << summary << " cases" << endl;
            summary = strtok(NULL, "?");
            cout << "Age range 41-60 years: " << summary << " cases" << endl;
            summary = strtok(NULL, "?");
            cout << "Age range 60+ years: " << summary << " cases" << endl;
            cout << endl;
        }
        else cout << summary << endl;
        summary = strtok(NULL, "?");
    }
}
