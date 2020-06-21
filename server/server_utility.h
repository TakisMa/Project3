#ifndef PROJECT3_SERVER_UTILITY_H
#define PROJECT3_SERVER_UTILITY_H

#include <netinet/in.h>
#include "CircularBuffer.h"
#include "WorkerList.h"

struct Arguments {
    CircularBuffer* buffer;
    WorkerList *wl;
    sockaddr *addr;
    socklen_t len;
};

void perror_exit(char *message);

int socket_setup(struct sockaddr_in *serverQ, struct sockaddr_in *serverS, struct sockaddr *serverQ_ptr, struct sockaddr *serverS_ptr, int &sockQ, int &sockS, int &queryPort, int &statisticsPort);

void print_summary(char *);

#endif //PROJECT3_SERVER_UTILITY_H
