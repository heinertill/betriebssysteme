#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int fibRec(int n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return (fibRec(n-1)+fibRec(n-2));
	}
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		time_t start_t, end_t;
		double diff_t;
		time(&start_t);
		
		printf("Fibonacci von %d ist: %d\n", atoi(argv[1]), fibRec(atoi(argv[1])));
		
		time(&end_t);
		diff_t = difftime(end_t, start_t);
		printf("Ausführzeit: %f\n", diff_t);
	} else {
		printf("Bitte gib eine Fibonacci Zahl an.\n");		
	}

	return 0;
}
