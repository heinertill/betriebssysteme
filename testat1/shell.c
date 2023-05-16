#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {

	// char pointer pointer for execv usage (ends with NULL)
	char *args[2];
	args[1] = NULL;

	int ret;
	int pid = -1;

	// loop the functionality of the program
	while(true) {
		// create fork
		pid = fork();

		// if pid == -1: something went wrong with the creation of the fork
		// if pid == 0: child process calls the pwd (print working directory)function
		// else: parent process calling for user action
		if (pid == -1) {
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			args[0] = "/bin/pwd";
			execv(args[0], args);
			exit(EXIT_SUCCESS);
		} else {
			wait(&ret);
			printf("> ");

			// create an input buffer with size of 100 characters
			char inputBuffer[100];
			fgets(inputBuffer, 100, stdin);

			// included for testing input string 
			//printf("You've entered: %s", inputBuffer);
			
			// array for execv inside parent, length of 10 for up to 8 parameters
			char *args2[10];
			char *delimiter = " ";
			char *ptr;
			
			// split the input into tokens, the first one will be the program name and the others are the parameters for the call
			ptr = strtok(inputBuffer, delimiter);
			
			char* programPath = malloc(strlen("/bin/") + strlen(ptr) + 1);
			strcpy(programPath, "/bin/");
			strcat(programPath, ptr);
			args2[0] = programPath;


			int i = 1;
			while (ptr != NULL) {
				args2[i] = ptr;
				ptr = strtok(NULL, delimiter);
				i++;
			}

			// create another fork to call the program
			int pid2 = fork();

			if (pid2 == -1) {
				exit(EXIT_FAILURE);
			} else if (pid2 == 0) {
				// this printf was used for testing the parameters
				printf("Calling %s\n", programPath);
				execv(args2[0], args2);
				exit(EXIT_SUCCESS);
			} else {
				wait(&ret);
				free(programPath);
			}
		}
	}

	return 0;
}
