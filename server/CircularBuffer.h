#ifndef PROJECT3_CIRCULARBUFFER_H
#define PROJECT3_CIRCULARBUFFER_H
#include <pthread.h>


class CircularBuffer {
private:
    int *buffer;
    int capacity;
    int count;
    int head;
    int tail;
public:
    int counter;
    bool isFull();

    bool isEmpty();

    int pop();

    int push(int desc);

    CircularBuffer(int capacity);

    ~CircularBuffer();
};


#endif //PROJECT3_CIRCULARBUFFER_H
