#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

#define MAX 1000

string line;
int x, y;
char M, N, l, r, F;

bool valid(int x, int y){
  return x < M && x >= 0 && y < N && y >= 0;
}

int main(){
  while(true){
    int x_1 = -1, y_1= -1, x_2= -1, y_2 = -1;
    getline(cin, line);
    stringstream stream(line);
    stream >> M >> N >> l >> F >> r;
    char frame[M][N], frame2[M][N], frame3[M][N];
    for(int i = 0; i < M; i++){cin.getline(frame[i], N);}
    for(int i = 0; i < M; i++){cin.getline(frame2[i], N);}
    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
        if(frame[i][j] == frame2[i][j]){
          frame3[i][j] = frame[i][j];
        }else if(frame[i][j] == F){
          if(x_1 == -1){
            x_1 = i; y_1 = j;
          }
          frame3[i][j] = frame2[i][j];
        }else if(frame2[i][j] == F){
          if(x_2 == -1){
            x_2 = i; y_2 = j;
          }
          frame3[i][j] = frame[i][j];
        }
      }
    }
    int diff_X = 2 * (x_2 - x_1), diff_Y = 2 * (y_2 - y_1);
    for(int i = 0; i < M; i++){
      for(int j = 0; j < N; j++){
        if(frame[i][j] == F){
          if(valid(i + diff_X , j + diff_Y)){frame3[i+diff_X][j+diff_Y] = F;}
        }
      }
    }
    for(int i = 0; i < M;i++){printf("%s\n", frame3[i]);}
    getline(cin,line);
  }

  return 0;
}
