#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "master.h"

int main(int argc, char **argv) {
	char *routeOfFileToRead = "./carrera.txt";
	FILE *filePointer = fileToRead(routeOfFileToRead);

	char* actualLine = NULL;
	size_t lineSize = 0;
	ssize_t charsInTheLine;
	/*char *routeOfFileToRead = getenv("HOLIS");

	if (routeOfFileToRead == NULL)
		routeOfFileToRead = "./carrera.txt";


	while ( (charsInTheLine = getline(&actualLine,&lineSize,filePointer) ) != -1){
		printf("Caracteres en la línea: %zu: \n",charsInTheLine);
		printf("%s",actualLine);
	}

	fclose(filePointer);*/

	createHorse();
}
