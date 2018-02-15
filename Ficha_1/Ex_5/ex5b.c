#include <stdio.h>
#include <string.h>

int main(int argc, char** argv, char** envp) {

	char* toCompare = "USER";

	while( strncmp((*envp), toCompare, 4) != 0){
		envp++;
	}

	printf("Hello %s!\n", (*envp)+5);

	return 0;
} 
