#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {

    struct termios termOld;
    struct termios termNew;
    char pass[100];
    
    char eco = '*';
    int i = 0;
    char c;

    write(STDOUT_FILENO, "Password? ", 10);

    tcgetattr(STDIN_FILENO, &termOld);
    termNew = termOld;
    termNew.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &termNew);

    while( read(STDIN_FILENO, &c, 1) && c != '\n') {
        pass[i++] = c;
        write(STDOUT_FILENO, &eco, 1);
    }
    
    pass[i] = 0;


    printf("\nPassword: %s\n", pass);
    
    tcsetattr(STDIN_FILENO, TCSANOW, &termOld);
    
    return 0;
}
