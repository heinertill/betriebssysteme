#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int pid;
	printf("Hauptprozess - SID: %d, PID: %d, PPID: %d\n", getsid(0), getpid(), getppid());

	pid = fork();

	if (pid > 0) {
		printf("Hallo vom Elternprozess - PID: %d, Kind-ID: %d\n", getpid(), pid);
	} else if (pid == 0) {
		printf("Hallo vom Kindprozess - PID: %d, PPID: %d\n", getpid(), getppid()); 
	} else {
		printf("Fork Fehler aufgetreten.");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
