#include "thread_functions.h"
#include "server_utility.h"
#include <iostream>
#include <cstring>

using namespace std;

void *init_function(void *args) {
    char rbuf[1024], sbuf[1024];
    CircularBuffer *buffer=((struct Arguments *) args)->buffer;
    while(true) {
        int fd;
        while(true) {
            fd = buffer->pop();
            if (fd != -1) break;
        }
        int i=read(fd, rbuf, sizeof(rbuf));
        if(i > 0) {
            if(strcmp(rbuf, "exit") == 0) break;
            pthread_mutex_lock(&print_mtx);
            cout << "Read from client: " << rbuf << endl;
            pthread_mutex_unlock(&print_mtx);
        }
        strcpy(sbuf, "Server answer");
        write(fd,sbuf, sizeof(sbuf));
        close(fd);
    }
    return NULL;
}
