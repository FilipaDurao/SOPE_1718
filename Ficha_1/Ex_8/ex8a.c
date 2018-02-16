#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv){

	int n, iter = 1;
	time_t t;

	if(argc != 3){
		printf("Wrong number of arguments\n");
		return 1;
	}

	srand((unsigned) time(&t));

	do{
		n = rand() % atoi(argv[1]);
		printf("%d - %d\n", iter, n);
		iter++;
	} while(n != atoi(argv[2]));


	return 0;
}
