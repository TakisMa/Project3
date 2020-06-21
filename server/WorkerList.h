#ifndef PROJECT3_WORKERLIST_H
#define PROJECT3_WORKERLIST_H


#include <cstring>
#include <unistd.h>

class WorkerListNode {
private:
    int rfd;
    char *workerIP;
    int workerPort;
    WorkerListNode *next;
public:
    void sendMessage(char *message);
    void recvMessage();


    WorkerListNode(int rfd, char *workerIP, int workerPort, WorkerListNode *next);
    ~WorkerListNode();
};

class WorkerList {
private:
    WorkerListNode *head;
public:
    void insert(int rfd, char *workerIP, int workerPort);
    void sendtoAll(char *message);
    void recvAll();

    WorkerList();
    ~WorkerList();

};

#endif //PROJECT3_WORKERLIST_H
