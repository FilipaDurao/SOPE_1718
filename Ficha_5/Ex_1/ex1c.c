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
    
        char num1;
        char num2;
    
        close(pipefd[0]);
    
        printf("First number\n");
        scanf("%s", &num1);
        
        printf("Second number\n");
        scanf("%s", &num2);
        
        write(pipefd[1], &num1, sizeof(num1));
        write(pipefd[1], &num2, sizeof(num2));
    }
    
    else{
        char n1[16];
        char n2[16];
        
        close(pipefd[1]);
        
        read(pipefd[0], n1, sizeof(char*));        
        read(pipefd[0], n2, sizeof(char*));
        
        int d1 = atoi(n1);
        int d2 = atoi(n2);
        
        printf("Num1 is %d\n", d1);
    
        /*printf("\n%d + %d = %d\n", d1, d2, d1+d2);
        printf("%d - %d = %d\n", d1, d2, d1-d2);
        printf("%d * %d = %d\n", d1, d2, d1*d2);
        
        if(d2 == 0){
            printf("Division undefined\n");
        }
        else{
            printf("%d / %d = %d\n", d1, d2, d1/d2); 
        }*/
    }
    
 return 0;
}
