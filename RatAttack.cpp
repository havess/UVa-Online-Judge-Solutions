#include <stdio.h>
#include <string.h>

int killed[1025][1025], TC, d , n, mx, my, mpop;

int clip(int x){
  if(x < 0) return 0;
  if(x > 1024) return 1024;
  return x;
}

void getKilledSums(int x, int y, int pop){
  for(int i = clip(x-d); i <= clip(x+d); i++){
    for(int j = clip(y-d); j <= clip(y+d); j++){
      killed[i][j] += pop;
    }
  }
}


int main(){
  scanf("%d", &TC);
  while(TC--){
    memset(killed,0,sizeof(killed));
    scanf("%d", &d);
    scanf("%d", &n);
    while(n--){
      scanf("%d %d %d",&mx,&my,&mpop);
      getKilledSums(mx, my, mpop);
    }
    int mX = -1, mY = -1, maxPop = 0;
    for(int i = 0; i < 1024;i++){
      for(int j = 0; j < 1024;j++){
        if(killed[i][j] > maxPop){
          maxPop = killed[i][j];
          mX = i;
          mY = j;
        }
      }
    }
    printf("%d %d %d\n",mX,mY,maxPop);
  }


}
