#include <stdio.h>
#include <cstdlib>

int f,r;

int main(){
  while(scanf("%d %d", &f, &r) == 2){
    float fT[f], rT[r];
    for(int i = 0; i < f; i++){scanf("%d", fT + i);}
    for(int i = 0; i < r; i++){scanf("%d", rT + i);}
    int ratio = 0;

    float ratios[r*f], spread = 0.0f;
    for(int i = 0; i < f; i++){
      for(int j = 0; j < r; j++){
        ratios[ratio++] = rT[j]/fT[i];
      }
    }
    std::qsort(ratios, r*f, sizeof(float), [](const void* a, const void* b){
       float arg1 = *static_cast<const float*>(a);
       float arg2 = *static_cast<const float*>(b);
       return (arg1 > arg2) - (arg1 < arg2);
   });
   for(int i = 1; i < r*f; i++){
     if(ratios[i]/ratios[i-1] > spread){spread = ratios[i]/ratios[i-1];}
   }
   printf("%.2f\n",spread);
  }
  return 0;
}
