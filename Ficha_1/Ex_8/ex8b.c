#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

int main (int argc, char** argv){

	struct tms ola;

	int n, iter = 1;
	time_t t;

	if(argc != 3){
		printf("Wrong number of arguments\n");
		return 1;
	}

	srand((unsigned) time(&t));

	do{
		n = rand() % atoi(argv[1]);
		printf("iter: %d - %d\n", iter, n);
		iter++;
	} while(n != atoi(argv[2]));


	clock_t times(struct tms *ola);

	printf("Real time: %d\nCPU sys time: %d\n", (int)ola.tms_utime, (int)ola.tms_stime);

	return 0;
}
