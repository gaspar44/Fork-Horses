/*
 * master.c
 *
 *  Created on: 23 sept. 2018
 *      Author: gaspar
 */
#define _GNU_SOURCE
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include "master.h"
#include "puntuacion.h"
#include "horse.h"



int getNumberOfProcessess(){
	srand(time(NULL) ^ getpid());
	int numberOfProcessesToCreate = (rand() % 10) + 1;

		if (numberOfProcessesToCreate >= 4)
			return numberOfProcessesToCreate;

		else
			return numberOfProcessesToCreate + 4;
}

FILE* fileToRead(char* routeToFile){
	FILE * filePointer;
	filePointer = fopen(routeToFile,"r");

	if (filePointer == NULL)
		exit(EXIT_FAILURE);

	return filePointer;

}

void createHorses(){
	int PID = getpid();
	const int NUMBER_OF_PROCESSES = getNumberOfProcessess();
	printf("aún no se ha creado el fork. Soy: %d\n",PID);
	pid_t createdProcesses[NUMBER_OF_PROCESSES];
	pid_t createdProcess;
	int status;

	for (int i = 0 ; i < NUMBER_OF_PROCESSES;i++){

		if ( PID == getpid()) {
			char* line = getLine(fileToRead("./carrera.txt"),i);
			createdProcess = fork();

			if (createdProcess < 0)
				exit(EXIT_FAILURE);

			else if (createdProcess == 0){
				int pointsStatus;
				pid_t point;

				printf("soy el proceso hijo: %d\n",getpid());

				char * horseResult = startRaceHorse(line,i);

				if ( (point = fork() ) == -1)
					exit(EXIT_FAILURE);

				else if(point == 0)
					writeResults(horseResult);

				else
					wait(&pointsStatus);

				exit(EXIT_SUCCESS);
			}

			else
				createdProcesses[i] = createdProcess;

		}

	}

	for (int i = 0; i < NUMBER_OF_PROCESSES ;i++)
		waitpid(createdProcesses[i],&status,0);

	exit(EXIT_SUCCESS);

}

char* getLine(FILE * fileToGetLine,int numberOfLineToRead){
	/* Según documentación, en el caso dado de que actualLine sea nula y el size_t 0, por dentro
	   Asocia el malloc adecuado*/
		char* actualLine = NULL;
		int startLine = 1;
		size_t lineSize = 0;
		ssize_t charsInTheLine;

		while ( (charsInTheLine = getline(&actualLine,&lineSize,fileToGetLine) ) != -1 && (startLine != numberOfLineToRead))
			startLine++;

		fclose(fileToGetLine);
		return actualLine;
}
