#include "thread_functions.h"
#include "server_utility.h"
#include <iostream>
#include <cstring>

using namespace std;

/*void init_function(CircularBuffer *buffer, struct sockaddr *sockaddr) {
    int fd = buffer->pop();
    char buf[1024];
    read(fd, buf, sizeof(buf));
    cout << "Buf: " << buf << endl;
}*/

void *init_function(void *args) {
    char buf[1024];
    CircularBuffer *buffer=((struct Arguments *) args)->buffer;
    while(true) {
        int fd = buffer->pop();
        cout << "before read() in thread" << endl;
        read(fd, buf, sizeof(buf));
        cout << "after read() in thread buf is " << buf <<endl;
        if(strcmp(buf, "end") == 0) break;
        cout << "Buf: " << buf << endl;
    }
}
