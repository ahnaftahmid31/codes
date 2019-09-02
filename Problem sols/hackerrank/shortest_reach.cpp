#include<bits/stdc++.h>
using namespace std;


#define  maxNodes 100005

vector <int> edgeof[maxNodes];
bool vis[maxNodes];
int level[maxNodes];

void bfs(int source)
{

  level[source] = 0;
  vis[source] = true;
  queue<int> q;
  q.push(source);
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int i = 0; i<edgeof[u].size(); i++)
    {
      int v = edgeof[u][i];
      if(!vis[v]){

        vis[v] = true;
        level[v] = level[u] + 6;
        q.push(v);
      }
    }
  }
}

void clearAll(int numNodes)
{
  for(int i = 0; i<=numNodes; i++)
  {
    edgeof[i].clear();
    vis[i] = false;
    level[i] = -1;

  }
}



int main()
{

  int queries;
  scanf("%d", &queries);
  for(int k = 0; k<queries; k++)
  {
    int numVertex, numEdges;
    scanf("%d %d", &numVertex, &numEdges);

    clearAll(numVertex);

    for(int i = 0; i<numEdges; i++)
    {
      int u, v;
      scanf("%d %d", &u, &v);
      edgeof[u].push_back(v);
      edgeof[v].push_back(u);

    }

    int source;
    scanf("%d", &source);

    bfs(source);

    for(int i = 1; i< numVertex; i++){
      if(i == source) continue;
      else{
        printf("%d ", level[i]);
      }
    }
    if(numVertex != source) printf("%d\n", level[numVertex]);
  }

}

