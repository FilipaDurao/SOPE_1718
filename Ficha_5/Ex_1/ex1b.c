#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

struct numbers{
    int number1;
    int number2;
};

int main(){
    
    int pipefd[2];

    // Criar o pipe
    pipe(pipefd);

    int pid = fork();

    // Processo pai
    if(pid > 0){
    
        int num1;
        int num2;
    
        close(pipefd[0]);
    
        printf("First number\n");
        scanf("%d", &num1);
        
        printf("Second number\n");
        scanf("%d", &num2);
        
        struct numbers n1;
        
        n1.number1 = num1;
        n1.number2 = num2;
        
        write(pipefd[1], &n1, sizeof(n1));
        
        close(pipefd[1]);
    }
    
    else{
        close(pipefd[1]);
        
        struct numbers n;
        
        read(pipefd[0], &n, 2*sizeof(int));   
    
        printf("\n%d + %d = %d\n", n.number1, n.number2, n.number1+n.number2);
        printf("%d - %d = %d\n", n.number1, n.number2, n.number1-n.number2);
        printf("%d * %d = %d\n", n.number1, n.number2, n.number1*n.number2);
        
        if(n.number2 == 0){
            printf("Division undefined\n");
        }
        else{
            printf("%d / %d = %d\n", n.number1, n.number2, n.number1/n.number2); 
        }
        
        close(pipefd[0]);
    }
    
 return 0;
}
