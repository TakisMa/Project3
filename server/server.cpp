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
pthread_mutex_t f_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t print_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_nonfull = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_nonempty = PTHREAD_COND_INITIALIZER;
bool finished_summaries;


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
    finished_summaries = false;
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
//    FD_SET(sockQ, &active_fd_set);
    FD_SET(sockS, &active_fd_set);
    int new_sockfd;
    clientlen = sizeof(client);
    int client_fd, worker_fd;
    int j = 0;


    struct timeval ts;
    ts.tv_sec = 60;
    ts.tv_usec = 0;
    int a= 0;
    while(true) {
        if(finished_summaries) break;
        finished_summaries = true;
        FD_ZERO(&read_fd_set);
        read_fd_set = active_fd_set;
        write_fd_set = active_fd_set;
        int k;
        if ((k = select(FD_SETSIZE, &read_fd_set, NULL, NULL, &ts)) <= 0){
            if(k == 0) break;
            if(errno==EINTR){
                cout << "error case " << endl;
                continue;
            }
            perror ("select");
            exit (EXIT_FAILURE);
        }
         /*Service all the sockets with input pending. */
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET (i, &read_fd_set)) {
                finished_summaries = false;
                if (i == sockS) {
                    if ((worker_fd = accept(sockS, (struct sockaddr *) &client, &clientlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    hostent *entry = gethostbyaddr(&client, clientlen, AF_INET);
                    char ip[16];
                    strcpy(ip, inet_ntoa(client.sin_addr));
                    cout << "worker ip: " << ip << endl;
                    char rbuf[1024];
                    read(worker_fd, rbuf, sizeof(rbuf));
//                    fd->push(worker_fd);
                    //                    print_summary(rbuf);
                    int wPort = atoi(rbuf);
                    FD_SET(worker_fd, &active_fd_set);
                    //                    FD_SET(wPort, &active_fd_set);
                    wl->insert(worker_fd, ip, wPort);
                }
                else {
                    char rbuf[1024];
                    int k = read(i, rbuf, sizeof(rbuf));
                    if(k < 0) perror("read from worker");
                    cout << "r: " << rbuf << endl;
                }
            }
        }
        ts.tv_sec = 1;
    }
    cout << "Server ready to receive client requests..." << endl;


    FD_ZERO(&active_fd_set);
    FD_SET(sockQ, &active_fd_set);

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
                    if((client_fd = accept(sockQ, (struct sockaddr *) &client, &clientlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }

                    fd->push(client_fd);
                }
            }
        }
    }

    return 0;
}




