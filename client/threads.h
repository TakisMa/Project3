#ifndef PROJECT3_THREADS_H
#define PROJECT3_THREADS_H

extern pthread_mutex_t file_mutex;
extern pthread_mutex_t count_mutex;
extern pthread_mutex_t print_mutex;
extern pthread_cond_t t_ready;
extern FILE *fp;
extern int t_count;
extern int t_num;

void *t_function(void*);

#endif //PROJECT3_THREADS_H
