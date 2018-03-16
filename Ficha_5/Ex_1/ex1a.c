#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    
    int pipefd[2];

    // Criar o pipe
    pipe(pipefd);

    int pid = fork();

    // Processo pai
    if(pid > 0){
    
        int num1 = 10;
        int num2 = 22;
    
        close(pipefd[0]);
    
        printf("First number\n");
        scanf("%d", &num1);
        
        printf("Second number\n");
        scanf("%d", &num2);
        
        write(pipefd[1], &num1, sizeof(int));
        write(pipefd[1], &num2, sizeof(int));
    }
    
    else{
        int n1;
        int n2;
        
        close(pipefd[1]);
        
        read(pipefd[0], &n1, sizeof(int));        
        read(pipefd[0], &n2, sizeof(int));
    
        printf("\n%d + %d = %d\n", n1, n2, n1+n2);
        printf("%d - %d = %d\n", n1, n2, n1-n2);
        printf("%d * %d = %d\n", n1, n2, n1*n2);
        
        if(n2 == 0){
            printf("Division undefined\n");
        }
        else{
            printf("%d / %d = %d\n", n1, n2, n1/n2); 
        }
    }
    
 return 0;
}
