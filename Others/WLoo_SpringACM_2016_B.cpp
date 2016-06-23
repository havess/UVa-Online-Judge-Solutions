#include <stdio.h>

int numCars,weight, weights[2000], fd[2000], bd[2000];

int main(){
  scanf("%d", &numCars);
  for(int i = 0; i < numCars; i++){
    scanf("%d", &weight);
    weights[i] = weight;
  }

  for(int i = 0; i < numCars; i++){
    for(int j = i; j < numCars;j++){
      if(weights[j] < weights[i]){ fd[i]++;}
    }
  }
  for(int i = 0; i < numCars; i++){
    for(int j = i; j < numCars;j++){
      if(weights[j] > weights[i]){ bd[i]++;}
    }
  }
  int maxLen = 0;
  for(int i = 0; i < numCars; i++){
    if(fd[i] + bd[i] + 1 > maxLen){maxLen = fd[i] + bd[i] + 1;}
  }
  printf("%d\n", maxLen);
  return 0;
}
