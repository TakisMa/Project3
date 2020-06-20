#ifndef DISEASEAGGREGATOR_FUNCTIONS_H
#define DISEASEAGGREGATOR_FUNCTIONS_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Record.h"
#include "Hashtable.h"
#include "RecordIDManagement.h"

using namespace std;



bool check_int(string );
int checkArguments(int argc, char** argv, int &workersNum, int &bufferSize, int &serverPort, char *&serverIP, string &path);
void swapD(struct Date *&a, struct Date *&b);
int partition(struct Date *array[], int low, int high);
void quickS(struct Date *array[], int low, int high);
int findDigits(int number);
int countCountries(string allCountries);
void sendEntry(Record *record, int fd2, int bufferSize);

int read_line(int fd, char *&readbuf, int bufferSize);
int read_line(int fd, char *&readbuf, int size, int bufferSize);
void write_line(int fd, char *&writebuf, int bufferSize, char *message);
int initialize_record(char *filepath, char *country, Hashtable *diseaseHT, Hashtable *countryHT, ID_Hashtable *idHT, int fd2, int bufferSize);
int sort_files(char* filepath, Date **&file_array);
char *create_fifo(char *fifo_name, pid_t childpid);
void print_summary(char *summary);

static int compare_dates(const void *p, const void *q);

int socket_setup(int &sock_desc, int servPort, char *servIP, struct sockaddr_in *&serv_addr) {
    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Failed creating socket\n");

    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr->sin_family = AF_INET;
    serv_addr->sin_addr.s_addr = inet_addr(servIP);
    //serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr->sin_port = htons(servPort);

}

#endif //DISEASEAGGREGATOR_FUNCTIONS_H