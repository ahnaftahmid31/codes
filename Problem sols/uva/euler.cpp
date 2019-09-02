#include<bits/stdc++.h>
using namespace std;

#define N 1000006

vector<int> adj[N];
int degree[N] = {0};

int main(){
  int n, e;
  int numOddDegree = 0;

  scanf("%d %d", &n, &e);
  for(int i = 0; i<e; i++){
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  for(int i = 1; i<=n; i++){
    if(degree[i] % 2 != 0){
      numOddDegree++;
    }
  }
  if(numOddDegree == 0){
    printf("Euler Circuit\n");
  }
  else if(numOddDegree == 2){
    printf("Euler Path\n");
  }
  else {
    printf("None\n");
  }
}
