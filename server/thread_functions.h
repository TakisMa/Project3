#ifndef PROJECT3_THREAD_FUNCTIONS_H
#define PROJECT3_THREAD_FUNCTIONS_H
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "CircularBuffer.h"

extern pthread_mutex_t mtx;
extern pthread_mutex_t mtx1;
extern pthread_mutex_t print_mtx;
extern pthread_cond_t cond_nonfull;
extern pthread_cond_t cond_nonempty;

void *init_function(void *args);

#endif //PROJECT3_THREAD_FUNCTIONS_H
