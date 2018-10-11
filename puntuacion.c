/*
 * puntuacion.c
 *
 *  Created on: 24 sept. 2018
 *      Author: gaspar
 */
#include "puntuacion.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

void writeResults(char* horseResult){
	int raceResult;

	raceResult = open("./puntuacion.txt",O_WRONLY);
	close(1);
	int checkStatusOfFile = dup(raceResult);

	if (checkStatusOfFile == -1){
		createFile("./puntuacion.txt");
		dup(raceResult);
	}

	write(1,horseResult, strlen(horseResult) + 1);
	exit(0);
}

void createFile(char * fileName){
	FILE *fileToCreate = fopen(fileName,"a");
	fclose(fileToCreate);

}
