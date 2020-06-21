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
    if(workerPort == 0) return;
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
    getpeername(rfd, (struct sockaddr*) &addr, addrlen);
//    serv_addr.sin_addr.s_addr = inet_addr(serverIP);
    //serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(workerPort);
    if (connect(wfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("Failed to connect to worker\n");
        exit(5);
    }
    write(wfd, sbuf, sizeof(sbuf));
}

void WorkerListNode::recvMessage() {
    char rbuf[1024];
    read(rfd, rbuf, sizeof(rbuf));
    cout << "A: " << rbuf << endl;
}

WorkerListNode::WorkerListNode(int fd, int workerPort, WorkerListNode *next) {
    this->rfd = fd;
    this->workerPort = workerPort;
    this->next = next;
}

WorkerListNode::~WorkerListNode() {
    delete next;
}

/* List functions */
void WorkerList::insert(int fd, int workerPort) {
    WorkerListNode *new_node = new WorkerListNode(fd, workerPort, head);
    head = new_node;
}

void WorkerList::sendtoAll(char *message) {
    WorkerListNode *tmp = head;
    while(tmp) {
        tmp->sendMessage(message);
    }
}

void WorkerList::recvAll() {
    WorkerListNode *tmp = head;
    while(tmp) {
        tmp->recvMessage();
    }
}

WorkerList::WorkerList() {
    head = NULL;
}

WorkerList::~WorkerList() {
    delete head;
}
