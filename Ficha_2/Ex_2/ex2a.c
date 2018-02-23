#include <stdio.h>

int main(int argc, char* argv[]) {

    if(argc != 3){
        printf("usage: copy <source> <destination>\n");
        return 1;
    }

    FILE * fs;
    FILE * fd;
    
    fs = fopen(argv[1], "r");
    fd = fopen(argv[2], "w");
    
    char c;
    
    while(fread(&c, 1, 1, fs) != 0 && !feof(fs)) {
        fwrite(&c, 1, 1, fd);
    }
    
    fclose(fs);
    fclose(fd);
    
    return 0;
}
