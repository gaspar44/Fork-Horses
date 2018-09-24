#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "master.h"

int main(int argc, char **argv){
	pid_t master;
	int status = 0;
	master = fork();

	if (master == -1)
		exit(EXIT_FAILURE);

	else if (master == 0)
		createHorses();

	else
		master = wait(&status);

	return 0;

}
