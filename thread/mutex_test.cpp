#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <pthread.h>
#include <cstring>

#define perror2(s, e) fprintf(stderr, "%s: %s\n", s, strerror(e))

char buf[25];
void *thread_f(void *);

int main() {
    pthread_t thr;
    int err;
    printf("Main Thread %ld running \n",pthread_self());
    pthread_mutex_init(&mtx, NULL);
    if (err = pthread_mutex_lock(&mtx)) { /* Lock mutex */
        perror2("pthread_mutex_lock", err);
        exit(1);
    }
    printf("Thread %lu: Locked the mutex\n", pthread_self());
/* New thread */
    if (err = pthread_create(&thr, NULL, thread_f, NULL)) {
        perror2("pthread_create", err);
        exit(1);
    }
    printf("Thread %ld: Created thread %lu\n", pthread_self(), thr);
    strcpy(buf, "This is a test message");
    printf("Thread %ld: Wrote message \"%s\" for thread %ld\n",
           pthread_self(), buf, thr);
    if (err = pthread_mutex_unlock(&mtx)) { /* Unlock mutex */
        perror2("pthread_mutex_unlock", err); exit(1);
    }
    printf("Thread %ld: Unlocked the mutex\n", pthread_self());
    if (err = pthread_join(thr, NULL)) { /* Wait for thread */
        perror2("pthread_join", err); exit(1); } /* termination */
    printf("Exiting Threads %ld and %ld \n", pthread_self(), thr);
    if (err = pthread_mutex_destroy(&mtx)) { /* Destroy mutex */
        perror2("pthread_mutex_destroy", err); exit(1); }
    pthread_exit(NULL);


    return 0;
}

void *thread_f(void *argp){ /* Thread function */
    int err;
    printf("Thread %ld: Just started\n", pthread_self());
    printf("Thread %ld: Trying to lock the mutex\n", pthread_self());
    if (err = pthread_mutex_lock(&mtx)) { /* Lock mutex */
        perror2("pthread_mutex_lock", err); exit(1); }
    printf("Thread %ld: Locked the mutex\n", pthread_self());
    printf("Thread %ld: Read message \"%s\"\n", pthread_self(), buf);
    if (err = pthread_mutex_unlock(&mtx)) { /* Unlock mutex */
        perror2("pthread_mutex_unlock", err); exit(1); }
    printf("Thread %ld: Unlocked the mutex\n", pthread_self());
    pthread_exit(NULL);
}