/* Exercise 3.2a: fork()
 *  *
 *   * Compile: gcc -o fork fork.c
 *    * Execute: ./fork
 *     *
 *      * Sven Reissmann (sven.reissmann@rz.hs-fulda.de)
 *       */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void) {
	int pid, ret;

			    /* Fork
				 *      */
    pid = fork ();

				    /* If fork failed, just exit
					 *      */
    if (pid == -1)
	    exit (EXIT_FAILURE);

					    /* This is the child (return of fork == 0)
						 *      * (say hello and exit)
						 *           */
	if (pid == 0) {
		printf ("Child  (PID = %6d, PPID = %6d)\n", getpid (), getppid ());
		char *argv[] = {"/bin/ls", "-l", 0};
		execvp(argv[0], argv);
		exit (EXIT_SUCCESS);
	}

						    /* This is the parent (return of fork > 0)
							 *      * (say hello, wait for child, and exit)
							 *           */
    if (pid > 0) {
	    printf ("Parent (PID = %6d, PPID = %6d)\n", getpid (), getppid ());

											        /* Calling wait() blocks the parent until the child exited
													 *          */
		wait (&ret);
		printf ("Child exited with %d\n", ret);

		exit (EXIT_SUCCESS);
    }
}


