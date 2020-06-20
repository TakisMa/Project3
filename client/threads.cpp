#include <string>
#include <iostream>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "client_utility.h"
#include "threads.h"
using namespace std;

void *t_function(void *args) {
    char * line = NULL;
    size_t len = 0;
    int sock_desc;
    char sbuff[1024];
    int servPort = ((struct arguments *) args)->servPort;
    char* servIP = new char[strlen(((struct arguments*) args)->servIP)];
    strcpy(servIP, ((struct arguments*) args)->servIP);
    struct sockaddr_in serv_addr;
    pthread_mutex_lock(&count_mutex);
    t_count++;
    pthread_mutex_unlock(&count_mutex);

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Failed creating socket\n");

    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(servIP);
	//serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(servPort);


    pthread_mutex_lock(&file_mutex);
    if(fp != NULL) {
        if (getline(&line, &len, fp) <= 0) {
            cerr << "EOF" << endl;
            fp = NULL;
        }
        pthread_mutex_unlock(&file_mutex);
        strcpy(sbuff, line);
    }
    else pthread_mutex_unlock(&file_mutex);



    /* καθε thread φτανει σε αυτο το σημειο και περιμενει. Μολις φτασει το το τελευταιο
     * (αρα count = total_threads) κανει broadcast ξεκινώντας όλα τα sleeping threads */
    if(t_count == t_num) {
        pthread_cond_broadcast(&t_ready);
    }
    else {
        pthread_cond_wait(&t_ready, &count_mutex);
    }
    pthread_mutex_unlock(&count_mutex);



    /* στελνει μηνυμα οσο υπαρχει ακομα κατι στο αρχειο για να διαβαστει ή αν το current thread εχει
     * διαβασει μια γραμμη που δεν εχει στειλει (και δεν ειναι κενη) */
    if(fp != NULL || line != NULL && strlen(line) != 0) {
        if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
            perror("Failed to connect to server\n");
        }
        write(sock_desc, sbuff, sizeof(sbuff));


        pthread_mutex_lock(&print_mutex);
        cout << "fd: " << sock_desc << " threads line sent: " << sbuff;
//        pthread_mutex_unlock(&print_mutex);
    }
    char rbuff[1024];
    int i = read(sock_desc, rbuff, sizeof(rbuff));
//    pthread_mutex_lock(&print_mutex);
    if(i > 0) cout << "ANSWER: " << rbuff << endl;
    cout << endl;
    pthread_mutex_unlock(&print_mutex);

    close(sock_desc);
    return NULL;
}
