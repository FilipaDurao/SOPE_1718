#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main() {

    int i = fork();
    
    // Parent writes
    if(i > 0){    
        printf("Hello");
    }

    else{
        int myParent = getppid();
        
        // Child waits for parent to write and then writes
        while(myParent == getppid()){
            usleep(10);
        }
    
        printf(" World!\n");
    }

    return 0;
}
