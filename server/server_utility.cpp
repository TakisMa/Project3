#include "server_utility.h"
#include <cstdlib>
#include <iostream>

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
    if (listen(sockQ, 5) < 0) perror_exit("Query listen");
    if (listen(sockS, 5) < 0) perror_exit("Statistics listen");

}
