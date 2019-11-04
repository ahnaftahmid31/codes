
#include<bits/stdc++.h>
using namespace std;


#define  maxNodes 100005

vector <int> edgeof[maxNodes];
bool vis[maxNodes];
int level[maxNodes];

int bfs(int source)
{
  int max = 0;
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
        level[v] = level[u] + 1;
        if(max < level[v]) max = level[v];
        q.push(v);
      }
    }
  }
  return max;
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


    int numVertex;
    scanf("%d", &numVertex);

    clearAll(numVertex);

    for(int i = 0; i<numVertex -1; i++)
    {
      int u, v;
      scanf("%d %d", &u, &v);
      edgeof[u].push_back(v);
      edgeof[v].push_back(u);

    }


    int res = (2*(numVertex -1)) - bfs(0);
    cout << res << endl;
}

