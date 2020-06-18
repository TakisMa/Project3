#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include "server_utility.h"
#include "CircularBuffer.h"
#include "thread_functions.h"
#include "../Functions.h"

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_nonfull = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_nonempty = PTHREAD_COND_INITIALIZER;



int main(int argc, char *argv[]) {
    int numThreads, bufferSize, queryPort, statisticsPort;
    int sockQ, sockS, newsock;
    fd_set active_fd_set, read_fd_set;
    struct sockaddr_in serverQ, serverS, client;
    socklen_t clientlen;
    CircularBuffer *fd;
    pthread_t *threads;
    pthread_t t;
    if(checkServerArguments(argc, argv, queryPort, statisticsPort, numThreads, bufferSize) < 0) {
        perror("initialization");
    }
    threads = new pthread_t[numThreads];
    fd = new CircularBuffer(bufferSize);
    struct sockaddr *serverQ_ptr=(struct sockaddr *)&serverQ;
    struct sockaddr *serverS_ptr=(struct sockaddr *)&serverS;
    struct sockaddr *clientptr=(struct sockaddr *)&client;
    struct hostent *rem;

    socket_setup(&serverQ, &serverS, serverQ_ptr, serverS_ptr, sockQ, sockS, queryPort, statisticsPort);

    struct Arguments *args = new struct Arguments;
    args->buffer = fd;
    args->addr = serverQ_ptr;
    args->len = sizeof(*serverQ_ptr);
    for(int i = 0; i < numThreads; i++) pthread_create(threads+i, NULL, init_function, (void*)args);
    delete args;

    FD_ZERO (&active_fd_set);
    FD_SET (sockQ, &active_fd_set);
    int new_sockfd;
    clientlen = sizeof(client);
    if((new_sockfd = accept(sockQ, (struct sockaddr *) &client, &clientlen)) < 0) {
        cout << "new_sockfd: " << new_sockfd << endl;
    }
    if (new_sockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    fd->push(new_sockfd);
    FD_SET(new_sockfd, &active_fd_set);

    while (true){
        /* Block until input arrives on one or more active sockets. */
        read_fd_set = active_fd_set;
        if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0){
            if(errno==EINTR){
                continue;
            }
            perror ("select");
            exit (EXIT_FAILURE);
        }
        /* Service all the sockets with input pending. */
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET (i, &read_fd_set)) {
                fd->push(i);
            }
        }
    }

    return 0;
}




