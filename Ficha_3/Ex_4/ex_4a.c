#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main() {

    int i = fork();
    
    // Child writes
    if(i == 0){
        write(STDOUT_FILENO,"Hello",5);
    }

    // Parent waits for child to finish and then writes
    else{
        wait();
        write(STDOUT_FILENO," World!",7);
    } 
    
    return 0;
}
