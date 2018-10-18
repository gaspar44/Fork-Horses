/*
 * puntuacion.c
 *
 *  Created on: 24 sept. 2018
 *      Author: gaspar
 */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "puntuacion.h"

void writeResults(char* horseResult){
	int raceResult = open("./puntuacion.txt",O_WRONLY|O_APPEND|O_CREAT,0666);
	close(1);

	if ( dup(raceResult) == -1)
		exit(EXIT_FAILURE);

	close(raceResult);
	printf("%s",horseResult);
	exit(EXIT_SUCCESS);
}
