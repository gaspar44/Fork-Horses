/*
 * master.c
 *
 *  Created on: 23 sept. 2018
 *      Author: gaspar
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "master.h"


int getNumberOfProcessess(){
	srand(time(NULL));
	int numberOfProccessesToCreate = rand() % 11;

		if (numberOfProccessesToCreate >= 4)
			return numberOfProccessesToCreate;

		else
			return numberOfProccessesToCreate + 4;
}

FILE* fileToRead(char* routeToFile){

	/* Según documentación, en el caso dado de que actualLine sea nula y el size_t 0, por dentro
	   Asocia el malloc adecuado*/

	FILE * filePointer;

	filePointer = fopen(routeToFile,"r");

	if (filePointer == NULL)
		exit(EXIT_FAILURE);

	return filePointer;

}

void createHorse(){
	int PID = getpid();
	printf("aún no se ha creado el fork. Soy: %d\n",PID);
	pid_t createdProccesses[4];
	pid_t createdProccess;

	for (int i = 0 ; i < 4;i++){

		if ( PID == getpid()) {
			createdProccess = fork();
			if (createdProccess < 0)
				exit(1);

			else if (createdProccess == 0){
				printf("soy el proceso hijo: %d\n",getpid());
				exit(0);
			}

			else
				createdProccesses[i] = createdProccess;
		}



			/*else
				printf("soy el proceso hijo: %d %d\n",getpid(),getppid());*/

	}

	sleep(5);
	for (int i =0; i < 4 ;i++)
		printf("%d\n",createdProccesses[i]);
}
