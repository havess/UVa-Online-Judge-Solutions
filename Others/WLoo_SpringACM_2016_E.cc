#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int  TC, n, temp;
double verD, horD,dist, heading, val;
string dir;

int main(){
  cin >> TC;
  while(TC--){
    verD = horD = heading = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> dir >> val;
      if(dir == "fd"){
        horD += val * cos(heading * acos(-1.0) / 180);
        verD += val * sin(heading * acos(-1.0) / 180);
      }else if(dir == "lf"){
        heading += val;
        heading = fmod(heading, 360);
      }else if(dir == "bk"){
        horD -= val * cos(heading * acos(-1.0) / 180);
        verD -= val * sin(heading * acos(-1.0) / 180);
      }else{
        heading -= val;
        heading = fmod(heading, 360);
      }
    }
    dist = sqrt(horD*horD + verD*verD);
    cout << floor(dist + 0.5) << endl;
  }

  return 0;
}
