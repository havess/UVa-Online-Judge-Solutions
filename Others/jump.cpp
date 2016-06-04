#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000

int n, in[MAX], visited[MAX];
vector<int> graph[2][MAX];

void generateGraph(){
  for(int i = 0; i < n; i++){
    graph[0][i].clear();
    graph[0][i].clear();
    visited[i] = 0;
  }
  for(int i = 0; i < n; i++){
    scanf("%d",in + i);
    if(in[i] + i < n){
      graph[0][in[i] + i ].push_back(i);
    }
    if(i - in[i] >= 0){
      graph[1][i - in[i]].push_back(i);
    }
  }
}

int main(){
  scanf("%d", &n);
  do{
    generateGraph();
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      int self = cur + in[cur];
      if(self < n){
        for(int i = 0; i < graph[1][self].size(); i++){
          int next = graph[1][self][i];
          if(!visited[next]){
            q.push(next);
            visited[next] = 1;
          }
        }
      }
      self = cur - in[cur];
      if(self >= 0){
        for(int i = 0; i < graph[0][self].size(); i++){
          int next = graph[0][self][i];
          if(!visited[next]){
            q.push(next);
            visited[next] = 1;
          }
        }
      }
    }
    int max;
    for(int i = 0; i < n; i++){
      if(visited[i]) max = i;
    }
    printf("%d\n", max);
    scanf("%d", &n);
  }while(n);
  return 0;
}
