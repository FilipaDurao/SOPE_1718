#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(){

    int i = fork();
    int pid1, pid2;
    
    if(i > 0){
        write(STDOUT_FILENO, "Hello ", 6);
    }

    else{
    
        pid1 = getppid();
        
        while(pid1 ==getppid()){
            usleep(10);
        }
        
        i = fork();
    
        if(i > 0){
            write(STDOUT_FILENO, "my ", 3);
        }
    
        else{
            pid2 = getppid();
        
            while(pid2 ==getppid()){
                usleep(10);
            }
        
            write(STDOUT_FILENO, "friends!\n", 9); 
        }
    }

    return 0;
}
