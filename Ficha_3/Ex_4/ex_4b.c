#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main() {

    int i = fork();
    
    if(i > 0){    
        printf("Hello");
    }

    else{
        int myParent = getppid();
        
        while(myParent == getppid()){
            usleep(10);
        }
    
        printf(" World!\n");
    }

    return 0;
}
