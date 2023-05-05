#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char* buffer;
	size_t bufsize = 32;
	size_t characters;
	
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL) {
		perror("Unable to allocate Buffer.");
		exit(1);
	}

	printf("Deine Eingabe: ");
	characters = getline(&buffer, &bufsize, stdin);
	
	char *token;
	token = strtok(buffer, " ");

	while (token != NULL) {
		printf("\n%s", token);

		token = strtok(NULL, " ");
	}
		
	return 0;
}
