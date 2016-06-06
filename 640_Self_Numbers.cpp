#include <stdio.h>
#include <math.h>
using namespace std;

int numbers[1000000] = {0};
int generate(int n){
  int next = n,copy = n;
  while(n){
    next += n % 10;
    n /= 10;
  }
  numbers[next] = 1;
  return numbers[copy];
}

int main(){
  for(int i = 1; i <= 1000000;i++){
    if(!generate(i)) {printf("%d\n", i);}
  }
  return 0;
}
