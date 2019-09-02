#include<bits/stdc++.h>
using namespace std;

#define  white 0
#define  grey 1
#define  black 2
#define  N 100005

vector <int> reverseG[N];
vector <int> adj[N];
vector <int> components[N];
stack <int> stk;
int numComp;
int color[N];
bool isVisited[N];
int inDegComp[N] = {0};
int indegree[N] = {0};
int numRightBat = 0;
int number_of_indegree_with_zero = 0;

void dfs(int u)
{
  color[u] = grey;

  for(int i = 0; i<adj[u].size(); i++)
  {
    int v = adj[u][i];
    if(color[v] == white)
    {
      dfs(v);
    }
  }

  color[u] = black;
  stk.push(u);
}

void dfs2(int u)
{
  components[numComp].push_back(u);
  isVisited[u] = true;
  for(int i = 0; i<reverseG[u].size(); i++)
  {
    int v = reverseG[u][i];
    if(!isVisited[v])
    {
      dfs2(v);
    }
  }
}

void dfs_init(int numVer)
{
  for(int i = 0; i<=numVer; i++)
  {
    color[i] = white;
    isVisited[i] = false;
    components[i].clear();
  }
  numComp = 0;

  for(int i = 0; i<numVer; i++) {
    if(color[i] == white)
    {
      dfs(i);
    }
  }

  while(!stk.empty())
  {
    int u = stk.top();
    stk.pop();
    if(!isVisited[u])
    {
      numComp++;
      dfs2(u);
    }
  }
  for(int i = 1; i<= numComp; i++){
    int size = components[i].size();
    for(int j = 0; j<size; j++){
      inDegComp[i] += indegree[components[i][j]];
    }
    if(size != 1) inDegComp[i] -= size;
    //cout << "Indegree of comp " << i << " is " << inDegComp[i] << " and size is " << size << "\n";
    if(inDegComp[i] == 0){
      numRightBat += size;
      number_of_indegree_with_zero ++;
    }
  }
  if(number_of_indegree_with_zero > 1) numRightBat = 0;
}

void printComponents()
{
  int i, j;
  for( i = 1; i<=numComp; i++)
  {
    cout << "comp no: " <<  i << " has --> ";
    for( j = 0; j<components[i].size() -1; j++)
    {
      cout << components[i][j] << ", ";
    }
    cout << components[i][j];
    cout << "\n";
  }
  cout << "total : " << numComp << "\n";
}
void printLoopingEdges(){
  int i, j;
  for(i = 1; i<=numComp; i++){
    cout << "comp " << i << " has " << numLoopingEdges[i] << " looping Edges\n";
  }

}

void printIndegree(int n){
  for(int i = 0; i<n; i++){
    cout << i << " has indegree " << indegree[i] << "\n";
  }
}

int main()
{

  int numVertex, numEdges;
  scanf("%d %d", &numVertex, &numEdges);

  for(int i = 0; i<= numVertex; i++)
  {
    adj[i].clear();
    reverseG[i].clear();
    indegree[i] = 0;
    inDegComp[i] = 0;
  }
  numRightBat = 0;

  for(int i = 0; i<numEdges; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    reverseG[v].push_back(u);
    indegree[v]++;
  }

  dfs_init(numVertex);
  printLoopingEdges();

}

