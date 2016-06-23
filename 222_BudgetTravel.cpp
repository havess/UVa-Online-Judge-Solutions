#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

typedef std::pair<float, float> ff;
typedef std::vector<ff> vff;

int n_stations, dS;
float distance, capacity, mpg, min,cost, tmpMin, gas, lastStop = 0.0f;
vff stations;

void calcMin(int i){
 float tempGas = gas, tempCost = cost;
 gas -= (stations[i].first - stations[i-1].first)/mpg;
 if(gas > 0){
   if( i == n_stations + 1){
     if(cost < min){ min = cost;}
     gas = tempGas;
     cost = tempCost;
     return;
   }
    calcMin(i+1);
    cost += floor(stations[i].second*(capacity-gas)+0.5)+200;
    gas = capacity;
    if(cost<min){
     calcMin(i+1);
   }
}
 gas = tempGas;
 cost = tempCost;
}


int main() {
 int t=1;
 while(scanf("%f", &distance) && distance >=0){
  scanf("%f %f %f %d", &capacity, &mpg, &cost, &n_stations);
  float s_dist, s_price;
  stations.push_back(ff(0,0));
  for(int i = 1; i <= n_stations; i++){
    scanf("%f %f",&s_dist, &s_price);
    stations.push_back(ff(s_dist, s_price));
  }
  stations.push_back(ff(distance,0));
  gas = capacity;
  min = 999999999;
  cost *=100;
  calcMin(1);
  printf("Data Set #%d\nminimum cost = $%.2f\n",t++, min/100);
 }
 return 0;
}
