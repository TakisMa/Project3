#include <string>
#include <iostream>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "client_utility.h"
#include "threads.h"
using namespace std;

void *t_function(void *args) {
//    char *filepath = new char[sizeof((char*)args)];
    char * line = NULL;
    size_t len = 0;
    int sock_desc;
    char sbuff[1024];
    int servPort = ((struct arguments *) args)->servPort;
    struct sockaddr_in serv_addr;
    pthread_mutex_lock(&count_mutex);
    t_count++;
    pthread_mutex_unlock(&count_mutex);

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Failed creating socket\n");

    bzero((char *) &serv_addr, sizeof (serv_addr));

    /*pthread_mutex_lock(&print_mutex);
    cout << "thread: " << pthread_self() << " has fd: " << sock_desc << endl;
    pthread_mutex_unlock(&print_mutex);*/

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(servPort);


    pthread_mutex_lock(&file_mutex);
    if(fp != NULL) {
        if (getline(&line, &len, fp) > 0) {
            pthread_mutex_lock(&print_mutex);
            cout << "thread: " << pthread_self() << " threads line: " << line << endl;
            pthread_mutex_unlock(&print_mutex);
        } else {
            cerr << "getline" << endl;
//        fclose(fp);
            fp = NULL;
        }
        pthread_mutex_unlock(&file_mutex);
        strcpy(sbuff, line);
    }
    else pthread_mutex_unlock(&file_mutex);



    if(t_count == t_num) {
        pthread_cond_broadcast(&t_ready);
    }
    else {
        pthread_cond_wait(&t_ready, &count_mutex);
    }
    pthread_mutex_unlock(&count_mutex);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        perror("Failed to connect to server\n");
    }
    write(sock_desc, sbuff, sizeof(sbuff));
    close(sock_desc);

}