#include "thread_functions.h"
#include "server_utility.h"
#include <iostream>
#include <cstring>

using namespace std;

void *init_function(void *args) {
    char buf[1024];
    CircularBuffer *buffer=((struct Arguments *) args)->buffer;
    while(true) {
        int fd;
        while(true) {
            fd = buffer->pop();
            if (fd != -1) break;
        }
        int i=read(fd, buf, sizeof(buf));
        if(i > 0) {
            if(strcmp(buf, "exit") == 0) break;
            pthread_mutex_lock(&print_mtx);
            cout << "Read from client: " << buf << endl;
            pthread_mutex_unlock(&print_mtx);
            close(fd);
        }
    }
    return NULL;
}
