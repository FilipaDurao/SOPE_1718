#include <stdio.h>
#include <stdlib.h>

void handler1() {
	printf("Executing exit handler 1\n");
}

void handler2() {
	printf("Executing exit handler 2\n");
}

int main(){

	atexit(handler1);
	atexit(handler2);

	printf("Main done!\n");

	return 0;
}
