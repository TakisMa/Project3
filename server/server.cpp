#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <pthread.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <errno.h>
#include <arpa/inet.h>
#include "server_utility.h"
#include "CircularBuffer.h"
#include "thread_functions.h"
#include "../common/Functions.h"
#include "WorkerList.h"

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t list_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t print_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_nonfull = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_nonempty = PTHREAD_COND_INITIALIZER;



int main(int argc, char *argv[]) {
    int numThreads, bufferSize, queryPort, statisticsPort;
    int sockQ, sockS, newsock;
    fd_set active_fd_set, read_fd_set, write_fd_set;
    struct sockaddr_in serverQ, serverS, client;
    socklen_t clientlen;
    CircularBuffer *fd;
    WorkerList *wl;
    pthread_t *threads;
    pthread_t t;
    if(checkServerArguments(argc, argv, queryPort, statisticsPort, numThreads, bufferSize) < 0) {
        perror("initialization");
    }
    threads = new pthread_t[numThreads];
    fd = new CircularBuffer(bufferSize);
    wl = new WorkerList();
    struct sockaddr *serverQ_ptr=(struct sockaddr *)&serverQ;
    struct sockaddr *serverS_ptr=(struct sockaddr *)&serverS;
    struct sockaddr *clientptr=(struct sockaddr *)&client;
    struct hostent *rem;

    socket_setup(&serverQ, &serverS, serverQ_ptr, serverS_ptr, sockQ, sockS, queryPort, statisticsPort);;

	char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    host_entry = gethostbyname(hostbuffer);
    IPbuffer = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));
    printf("Host IP: %s\n", IPbuffer);

    struct Arguments *args = new struct Arguments;
    args->buffer = fd;
    args->addr = serverQ_ptr;
    args->len = sizeof(*serverQ_ptr);
    args->wl = wl;
    for(int i = 0; i < numThreads; i++) pthread_create(threads+i, NULL, init_function, (void*)args);


    FD_ZERO(&active_fd_set);
    FD_SET(sockQ, &active_fd_set);
    FD_SET(sockS, &active_fd_set);
    int new_sockfd;
    clientlen = sizeof(client);


    while (true){
        /* Block until input arrives on one or more active sockets. */
        read_fd_set = active_fd_set;
        write_fd_set = active_fd_set;
        if (select (FD_SETSIZE, &read_fd_set, &write_fd_set, NULL, NULL) < 0){
            if(errno==EINTR){
                continue;
            }
            perror ("select");
            exit (EXIT_FAILURE);
        }
        /* Service all the sockets with input pending. */
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET (i, &read_fd_set)) {
                if(i == sockQ) {
                    if((new_sockfd = accept(sockQ, (struct sockaddr *) &client, &clientlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }

                    fd->push(new_sockfd);
                }
                else if(i == sockS) {
                    if((new_sockfd = accept(sockS, (struct sockaddr *) &client, &clientlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    char rbuf[1024];
                    read(new_sockfd, rbuf, sizeof(rbuf));
//                    print_summary(rbuf);
                    int wPort = atoi(rbuf);
                    FD_SET(new_sockfd, &active_fd_set);
                    FD_SET(wPort, &active_fd_set);
                    pthread_mutex_lock(&list_mtx);
                    cout << "inserted workerPort: " << wPort << endl;
                    wl->insert(new_sockfd, wPort);
                    pthread_mutex_unlock(&list_mtx);
                }
                else {
                    char rbuf[1024];
                    read(i, rbuf, sizeof(rbuf));
//                    print_summary(rbuf);
                    /*pthread_mutex_lock(&list_mtx);
                    wl->insert(i, 0);
                    pthread_mutex_unlock(&list_mtx);*/
                }
            }
        }
    }

    return 0;
}




