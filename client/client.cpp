#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include "../Functions.h"
#include "client_utility.h"
#include <cstring>
#include "client_utility.h"
#include "threads.h"

#define MAX_SIZE 10

using namespace std;

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t t_ready = PTHREAD_COND_INITIALIZER;
FILE *fp;
int t_count;
int t_num;


int main(int argc, char *argv[]) {
    int numThreads, servPort;
    hostent *servIP;
    char *queryFile;

    if(checkClientArguments(argc, argv, queryFile, numThreads, servPort, servIP) < 0) {
        perror("initialization");
    }
    pthread_t *t = new pthread_t[numThreads];

    int sock_desc;
    t_count = 0;
    t_num = numThreads;
    fp = fopen(queryFile, "r");


    struct arguments *args = new struct arguments;

    args->servPort = servPort;

    for(int i = 0; i < numThreads; i++) pthread_create(&t[i], NULL, t_function, (void*)args);
    for(int i = 0; i < numThreads; i++) pthread_join(t[i], NULL);

    while(fp!=NULL) {
        t_count = 0;
        for(int i = 0; i < numThreads; i++) pthread_create(&t[i], NULL, t_function, (void*)args);
        for(int i = 0; i < numThreads; i++) pthread_join(t[i], NULL);
    }


    /*struct sockaddr_in serv_addr;
    char sbuff[MAX_SIZE],rbuff[MAX_SIZE];

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed creating socket\n");
    }

    bzero((char *) &serv_addr, sizeof (serv_addr));


    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(servPort);


    while(true) {
        if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
            printf("Failed to connect to server\n");
            return -1;
        }
        printf("Connected successfully - Please enter string\n");
        if(strcmp(sbuff, "end") == 0) break;

        while (fgets(sbuff, MAX_SIZE, stdin) != NULL) {
            send(sock_desc, sbuff, strlen(sbuff), 0);

            if (recv(sock_desc, rbuff, MAX_SIZE, 0) == 0)
                printf("Error");
            else
                fputs(rbuff, stdout);

            bzero(rbuff, MAX_SIZE);//to clean buffer-->IMP otherwise previous word characters also came
            printf("Received %s from server\n", rbuff);
        }
    }

    close(sock_desc);*/
    return 0;
}