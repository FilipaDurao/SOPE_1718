/*
	On the terminal do
	export USER_NAME="whatever the name is"
	and execute this program on the same terminal
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv, char** envp) {

	printf("Hello %s!\n", getenv("USER_NAME"));

	return 0;
} 
