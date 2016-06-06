#include <stdio.h>
#include <cstring>

bool solutions ;
int numbers[10] = {0},N;

bool isValid(int n){
  while(n){
    if(numbers[n%10]){return false;}
    numbers[n%10] = 1;
    n /=10;
  }
  return true;
}

int main(){
  scanf("%d", &N);
  while(true){
    solutions = false;
    for(int i = 1234; i <= 98765; i++){
      memset(numbers,0,sizeof(numbers));
      if(i < 10000 || i*N < 10000){numbers[0] = 1;}
      if(!isValid(i) || !isValid(i*N)){continue;}
      for(int k = 0; k < 10;k++){
        if(!numbers[k])goto next;
      }
      solutions = true;
      printf("%05d / %05d = %d\n",i*N, i, N);
      next:;
    }
    if(!solutions){
      printf("There are no solutions for %d.\n", N);
    }
    scanf("%d", &N);
    if(!N){return 0;}
    printf("\n");
  }
}
