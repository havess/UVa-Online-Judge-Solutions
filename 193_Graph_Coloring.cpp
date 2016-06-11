#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

typedef std::vector<int> vi;

int TC, nodes, edges, v1, v2, maxSet = 0;

vi solutionSet, combSet, q;
int colors[100];
std::vector<vi> graph;

void colour(int node){
  if(node >= nodes){
    if(combSet.size() > maxSet){
      solutionSet = combSet;
      maxSet = combSet.size();
    }
  }else{
    bool blackNeighbor = false;
    for(int i : graph[node]){
      if(colors[i] == 1){
        blackNeighbor = true;
        break;
      }
    }
      if(!blackNeighbor){
        combSet.push_back(node);
        colors[node] = 1;
        colour(node + 1);
        combSet.pop_back();
      }
      colors[node] = 2;
      colour(node + 1);
    }

}

int main(){
  scanf("%d",&TC);
  while(TC--){
    maxSet = 0;
    graph.clear();
    combSet.clear();
    solutionSet.clear();
    scanf("%d %d", &nodes, &edges);
    for(int i = 0; i < nodes; i++){
      graph.push_back(vi());
      colors[i] = 0;
    }
    for(int i = 0; i < edges; i++){
      scanf("%d %d",&v1, &v2);
      graph[v1 - 1].push_back(v2 - 1);
      graph[v2 - 1].push_back(v1 - 1);
    }
    colour(0);
    printf("%d\n%d", maxSet, solutionSet[0]+1);
    for(int i = 1; i < maxSet; i++){
      printf(" %d", solutionSet[i]+1);
    }
    printf("\n");
  }
}
