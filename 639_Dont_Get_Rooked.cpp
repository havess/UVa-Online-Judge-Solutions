#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

char c;
std::string line;
int n, grid[4][4];
int combinations[] = {0,1,15,511,65535};
int maxes[] = {0,1,2,5,8};

int countSetBits(int n){
  int counter = 0;
  for(;n;counter++){
    n &= n - 1;
  }
  return counter;
}

int main(){
  while(1){
    scanf("%d", &n);
    if(!n){return 0;}

    for(int i  = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        std::cin >> c;
        grid[i][j] = (c == 'X') ? -1:0;
      }
    }
    int max = 0, numRooks= 0;
    for(int comb = 1; comb <= combinations[n]; comb++){
      numRooks = countSetBits(comb);
      int combGrid[4][4], index = 0;
      for(int i = 0; i < n;i++)for(int j = 0; j < n; j++) {combGrid[i][j] = grid[i][j];}
      if(numRooks <= max || numRooks > maxes[n]){continue;}
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
          int rook = comb & (1 << index++);
          if(rook && grid[i][j] == -1){
            goto next;
          }else if(rook){
            combGrid[i][j] = 1;
          }
        }
      }
      bool rookR,rookC;
      for(int i = 0; i < n; i++){
        rookR = false;rookC = false;
        for(int j = 0; j < n; j++){
          if((rookR && combGrid[i][j] == 1) || (rookC && combGrid[j][i] == 1)){goto next;}
          rookR = (combGrid[i][j] == 1 || (!combGrid[i][j] && rookR));
          rookC = (combGrid[j][i] == 1 || (!combGrid[j][i] && rookC));
        }
      }
      max = numRooks;
      if(max == maxes[n]){break;}
      next:;
    }
    printf("%d\n",max);
  }
  return 0;
}
