#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[]) {
	if (argc >= 2) {
		printf("Name des Programms: %s\n", argv[0]);
		for (int i = 1; i < argc; i++) {
			printf("%s\n", argv[i]);
		} 
	} else {
		printf("Gib mindestens 1 Argument an..\n");		
	}																							

	return 0;
}
