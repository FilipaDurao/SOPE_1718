// PROGRAMA p01a.c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
    printf("In SIGINT handler ...\n");
}

int main(void){
    if (signal(SIGINT,sigint_handler) < 0){
        fprintf(stderr,"Unable to install SIGINT handler\n");
        exit(1);
    }
    
    int left = 30;
    
    while(left != 0){
        printf("Sleeping for 30 seconds ...\n");
        left = sleep(left);
        printf("Waking up ...\n");
    }
    
    exit(0);
} 
