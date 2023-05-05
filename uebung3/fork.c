#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int a_global = 10;

int main(int argc, char **argv) {
	int pid;
	int a_priv = 10;

	printf("global address before fork: %p - local address before fork: %p\n", &a_global, &a_priv);

	printf("Hauptprozess - SID: %d, PID: %d, PPID: %d\n", getsid(0), getpid(), getppid());

	printf("\n--- Creating forks --- \n\n");

	pid = fork();


	if (pid > 0) {
		printf("Hallo vom Elternprozess - PID: %d, Kind-ID: %d\n", getpid(), pid);
		printf("PARENT: global address after fork: %p - local address after fork: %p\n", &a_global, &a_priv);
	} else if (pid == 0) {
		printf("Hallo vom Kindprozess - PID: %d, PPID: %d\n", getpid(), getppid()); 
		printf("CHILD: global address after fork: %p - local address after fork: %p\n", &a_global, &a_priv);
	} else {
		printf("Fork Fehler aufgetreten.");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
