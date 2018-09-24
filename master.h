#ifndef MASTER_H
#define MASTER_H
#include <stdio.h>

int getNumberOfProcessess();
FILE* fileToRead(char *routeToTheFile);
void createHorses();
char* getLine(FILE * fileToGetLine,int numberOfLineToRead);
#endif
