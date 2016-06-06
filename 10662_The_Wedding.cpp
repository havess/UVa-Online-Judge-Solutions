#include <stdio.h>
#include <limits>

int t_N, r_N, h_N;

int main(){
  while(scanf("%d %d %d", &t_N, &r_N, &h_N) == 3){
    int  t[t_N], r[r_N],h[h_N];
    char tr[t_N][r_N], rh[r_N][h_N], ht[h_N][t_N];
    for(int i = 0; i < t_N; i++){scanf("%d",t+i ); for(int j = 0; j < r_N; j++){scanf("%d", &tr[i][j]);}}
    for(int i = 0; i < r_N; i++){scanf("%d",r+i ); for(int j = 0; j < h_N; j++){scanf("%d", &rh[i][j]);}}
    for(int i = 0; i < h_N; i++){scanf("%d",h+i ); for(int j = 0; j < t_N; j++){scanf("%d", &ht[i][j]);}}
    int price = std::numeric_limits<int>::max(), T = -1, R, H;
    for(int i = 0;i < t_N; i++){
      for(int j = 0; j < r_N; j++){
        if(!tr[i][j]){
          for(int k = 0; k < h_N;k++){
            if(!rh[j][k] && !ht[k][i] && t[i] + r[j] + h[k] < price){
              T = i; R = j; H = k; price = t[i] + r[j] + h[k];
            }
          }
        }
      }
    }
    if(T == -1){
      printf("Don't get married!\n");
    }else{
      printf("%d %d %d:%d\n", T,R,H,price );
    }
  }
  return 0;
}
