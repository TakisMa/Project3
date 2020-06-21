#ifndef PROJECT3_WORKERLIST_H
#define PROJECT3_WORKERLIST_H


#include <cstring>
#include <unistd.h>

class WorkerListNode {
private:
    int rfd;
    int workerPort;
    WorkerListNode *next;
public:
    void sendMessage(char *message);
    void recvMessage();


    WorkerListNode(int fd, int workerPort, WorkerListNode *next);
    ~WorkerListNode();
};

class WorkerList {
private:
    WorkerListNode *head;
public:
    void insert(int fd, int workerPort);
    void sendtoAll(char *message);
    void recvAll();

    WorkerList();
    ~WorkerList();

};

#endif //PROJECT3_WORKERLIST_H
