#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc >= 3) {
		printf("Name des Programms: %s\n", argv[0]);
		printf("Name des zweiten Programms: %s\n", argv[1]);

		char **args2 = &argv[1];
		execvp("./prog2.o", args2);
	} else {
		printf("Gib mindestens 1 Argument an..\n");		
	}																							

	return 0;
}
