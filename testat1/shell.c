#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

#define MAX_ARGS 10

int main(int argc, char **argv) {

	// char pointer pointer for execv usage (ends with NULL and starts with program name)
	char *args[MAX_ARGS + 2];
	int ret;
	int pid = -1;

	// loop the functionality of the program
	while(true) {
		// create buffer for working directory and continue printing it with the > symbol
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL) {
			printf("%s> ", cwd);
		} else {
			perror("getcwd");
			exit(EXIT_FAILURE);
		}

		// create an input buffer with size of 100 characters
		char inputBuffer[100];
		fgets(inputBuffer, 100, stdin);
		
		// replace the newline character with the string termination character
		inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

		// included for testing input string 
		//printf("You've entered: %s", inputBuffer);
		
		// tokenize the input into the program name and the parameters
		char *token = strtok(inputBuffer, " ");
		int argCount = 0;
		
		while (token != NULL && argCount < MAX_ARGS) {
			args[argCount] = token;
			argCount++;
			token = strtok(NULL, " ");
		}

		// last argument should be NULL
		args[argCount] = NULL;

		// before creating a fork, check if the wanted program is cd, then following code should execute
		if (strcmp(args[0], "cd") == 0) {
			if (argCount > 0) {
				if (chdir(args[1]) == -1) {
					perror("cd");
				}
			} else {
				fprintf(stderr, "Missing Argument for cd.");
			}
			continue; //skip usual execution of shell program
		}

		// also check if input is exit, then program should stop
		if (strcmp(args[0], "exit") == 0) {
			exit(EXIT_SUCCESS);
		}

		// create another fork to call the program
		int pid2 = fork();

		if (pid2 == -1) {
			exit(EXIT_FAILURE);
		} else if (pid2 == 0) {
			// this printf was used for testing the parameters
			//printf("Calling %s\n", args[0]);
			execvp(args[0], args);
			exit(EXIT_SUCCESS);
		} else {
			wait(&ret);
		}
	}
	return 0;
}
