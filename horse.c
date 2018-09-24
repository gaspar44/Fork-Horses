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
#include <time.h>
#include "horse.h"

int getRaceTime() {
	srand(time(NULL));
	int raceTime = rand() % 60;

		if (raceTime >= 30)
			return raceTime;

		else
			return raceTime + 30;
}

void startRaceHorce(char* horseRiderData ){
	printf("soy: %s\n",horseRiderData);

}
