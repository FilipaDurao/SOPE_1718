#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv){

	int n, iter = 1;
	time_t t, ti, tf;

	if(argc != 3){
		printf("Wrong number of arguments\n");
		return 1;
	}

	time(&ti);

	srand((unsigned) time(&t));

	do{
		n = rand() % atoi(argv[1]);
		printf("iter: %d - %d\n", iter, n);
		iter++;
	} while(n != atoi(argv[2]));


	time(&tf);

	printf("Tempo de execucao: %d\n", (int)(tf-ti));

	return 0;
}
