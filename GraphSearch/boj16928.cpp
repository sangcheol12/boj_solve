#include <bits/stdc++.h>
using namespace std;

int graph[105];
int visited[105];

void bfs(int st) {
  queue<int> q;
  q.push(st);
  visited[st] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int i=1; i<=6; i++) {
      int nxt = cur + i;
      if(graph[nxt]) nxt = graph[nxt];
      if(visited[nxt] != -1) continue;
      q.push(nxt);
      visited[nxt] = visited[cur] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m; cin >> n >> m;
  for(int i=0; i<n+m; i++) {
    int u,v;
    cin >> u >> v;
    graph[u] = v;
  }
  fill(visited,visited+101,-1);
  bfs(1);
  cout << visited[100] << '\n';
}
