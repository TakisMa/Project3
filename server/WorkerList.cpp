#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "WorkerList.h"

using namespace std;

/* Node functions */

void WorkerListNode::sendMessage(char *message) {
    char sbuf[1024];
    strcpy(sbuf, message);
    int wfd;
    struct sockaddr_in addr;
    struct hostent *host;
    socklen_t *addrlen;
    if((wfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed creating socket\n");
    }
    bzero((char *) &addr, sizeof (addr));

    addr.sin_family = AF_INET;
//    getpeername(rfd, (struct sockaddr*) &addr, addrlen);
    addr.sin_addr.s_addr = inet_addr(workerIP);
    //serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(workerPort);
    if (connect(wfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("Failed to connect to worker\n");
        exit(5);
    }
    write(wfd, sbuf, sizeof(sbuf));
    cout << "wrote to worker: " << sbuf << endl;
//    close(wfd);
    if(next) next->sendMessage(message);
}

void WorkerListNode::recvMessage(int fd) {
    char rbuf[1024];
    while(true) {
        int i = read(rfd, rbuf, sizeof(rbuf));
        if(strcmp(rbuf, "END") == 0) break;
        cout << "server answer: " << rbuf << endl;
        if (i >= 0) {
            write(fd, rbuf, sizeof(rbuf));
            /*cout << "A: " << rbuf << endl;*/
        } else if (i < 0) {
            perror("recvMessage()");
            strcpy(rbuf, "ERROR");
            write(fd, rbuf, sizeof(rbuf));
            return;
        }
    }
    if(next) next->recvMessage(fd);
}

WorkerListNode::WorkerListNode(int rfd, char *workerIP, int workerPort, WorkerListNode *next) {
    this->rfd = rfd;
    this->workerIP = workerIP;
    this->workerPort = workerPort;
    this->next = next;
}

WorkerListNode::~WorkerListNode() {
    delete next;
}

/* List functions */
void WorkerList::insert(int fd, char* workerIP, int workerPort) {
    head = new WorkerListNode(fd, workerIP, workerPort, head);
}

void WorkerList::sendtoAll(char *message) {
    if(head) head->sendMessage(message);
}

void WorkerList::recvAll(int fd) {
   if(head) head->recvMessage(fd);
}

WorkerList::WorkerList() {
    head = NULL;
}

WorkerList::~WorkerList() {
    delete head;
}
