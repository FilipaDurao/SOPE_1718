#include <stdio.h>
int main(int argc, char* argv[]) {
  if(argc == 1){
    printf("Hello!\n");
    return 1;
  }
  int count = argc -1;
  int i = 1;
  printf("Hello");
  while(count != 0){
    printf(" %s", argv[i]);
    count --;
    i++;
  }
  printf("!\n");
  return 0;
} 
