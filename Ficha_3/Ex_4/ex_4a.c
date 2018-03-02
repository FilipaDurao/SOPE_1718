#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main() {

    int i = fork();
    
    if(i == 0){
        write(STDOUT_FILENO,"Hello",5);
    }

    else{
        wait();
        write(STDOUT_FILENO," World!",7);
    } 
    
    return 0;
}
