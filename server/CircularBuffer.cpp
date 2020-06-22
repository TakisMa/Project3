#include "CircularBuffer.h"
#include <iostream>
#include <unistd.h>

extern pthread_mutex_t mtx;
extern pthread_cond_t cond_nonfull;
extern pthread_cond_t cond_nonempty;

using namespace std;


bool CircularBuffer::isFull() {
    return count == capacity;
}

bool CircularBuffer::isEmpty() {
    return count == 0;
}

int CircularBuffer::pop() {
    pthread_mutex_lock(&mtx);
    if(count == 0) pthread_cond_wait(&cond_nonempty, &mtx);
    int tmp = buffer[head];
    buffer[head] = -1;
    head = (head + 1) % capacity;
    count --;
    pthread_mutex_unlock(&mtx);
    pthread_cond_signal(&cond_nonfull);
    return tmp;
}

int CircularBuffer::push(int desc) {
    pthread_mutex_lock(&mtx);
    if(count == capacity) pthread_cond_wait(&cond_nonfull, &mtx);
    count ++;
    buffer[tail] = desc;
    tail = (tail + 1) % capacity;
    pthread_mutex_unlock(&mtx);
    pthread_cond_signal(&cond_nonempty);
    return 0;
}

CircularBuffer::CircularBuffer(int capacity) {
    this->capacity = capacity;
    buffer = new int[capacity];
    for(int i = 0; i < capacity; i++) buffer[i] = -1;
    count = 0;
    counter = 0;
    head = 0;
    tail = 0;
}

CircularBuffer::~CircularBuffer() {
    delete [] buffer;
}
