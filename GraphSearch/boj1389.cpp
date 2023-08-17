#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int visited[101];
vector<int> G[101];

void bfs(int st) {
  queue<int> q;
  q.push(st);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int nxt : G[cur]) {
      if(!visited[nxt]) {
        q.push(nxt);
        visited[nxt] = visited[cur] + 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,min=1234567890,kb;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u,v;
    cin >> u >> v;
    u--,v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i=0; i<n; i++) {
    int sum=0;
    bfs(i);
    for(int j=0; j<n; j++) {
      if(i==j)
        continue;
      sum+=visited[j];
    }
    if(sum<min) {
      min = sum;
      kb=i+1;
    }
    memset(visited,0,sizeof(visited));
  }
  cout << kb;
}
