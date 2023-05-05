#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int fibRec(int n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return (fibRec(n-1) + fibRec(n-2));
	}
}

int main(int argc, char **argv) {
	pid_t pids[10];
	int amountOfChildren = 10;

	printf("Hauptprozess - SID: %d, PID: %d, PPID: %d\n", getsid(0), getpid(), getppid());
	printf("\n--- Creating forks --- \n\n");
	
	// start children
	for (int i = 0; i < amountOfChildren; i++) {
		if ((pids[i] = fork()) < 0) {
			printf("Fork Fehler aufgetreten\n");
			exit(EXIT_FAILURE);
		} else if (pids[i] == 0) {
			printf("Hallo vom Kindprozess - PID: %d, PPID: %d\n", getpid(), getppid()); 
			for (int j = 0; j < 10; j++) {
				fibRec(40);
				printf("Kind (PID: %d) Durchlauf %i\n", getpid(), j);
			}
			exit(0);
		}
	}

	int status;
	pid_t pid;
	while (amountOfChildren > 0) {
		pid = wait(&status);
		amountOfChildren--;
	}


	/*
	if (pid > 0) {
		printf("Hallo vom Elternprozess - PID: %d, Kind-ID: %d\n", getpid(), pid);
	} else if (pid == 0) {
		printf("Hallo vom Kindprozess - PID: %d, PPID: %d\n", getpid(), getppid()); 
	} else {
		printf("Fork Fehler aufgetreten.\n");
		exit(EXIT_FAILURE);
	}
	*/

	exit(EXIT_SUCCESS);
}
