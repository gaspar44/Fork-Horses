/*
 * horse.c
 *
 *  Created on: 24 sept. 2018
 *      Author: gaspar
 */
#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "horse.h"
#include <string.h>

int getRaceTime() {
	srand(time(NULL) ^ getpid());
	int raceTime = rand() % 60;

		if (raceTime >= 30)
			return raceTime;

		else
			return raceTime + 30;
}

char* startRaceHorse(char* horseRiderData,int numberOfHorse ){
	int horseRaceTime = getRaceTime();
	char stringedHorseRaceTime[100];
	char* result = 0;

	sprintf(stringedHorseRaceTime,"%d",horseRaceTime);
	sleep(horseRaceTime);

	result = malloc(strlen(horseRiderData) + strlen(stringedHorseRaceTime) + 5);
	strcpy(result,horseRiderData);
	strtok(result,"\n");
	strcat(result,";");
	strcat(result,stringedHorseRaceTime);
	strcat(result,"\n");
	return result;

}
