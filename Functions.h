#ifndef DISEASEMONITOR_FUNCTIONS_H
#define DISEASEMONITOR_FUNCTIONS_H
#include <string>

using namespace std;

bool check_int(char* );

int checkClientArguments(int argc, char **argv, char *&filepath, int &threadNum, int &servPort, hostent *servIP);

int checkServerArguments(int argc, char** argv, int &queryPort, int &statisticsPort, int &numThreads, int &bufferSize);

string getWord(string str);

#endif //DISEASEMONITOR_FUNCTIONS_H
