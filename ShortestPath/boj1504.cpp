#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1234567890
using namespace std;

vector<pair<int,int>> G[801];
int dist[801];
int N,E;

void dijkstra(int st) {
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,st));
  dist[st] = 0;
  while(!pq.empty()) {
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    for(int i=0; i<G[cur].size(); i++) {
      int next = G[cur][i].first;
      int ncost = G[cur][i].second;
      if(dist[next] > cost+ncost) {
        dist[next] = cost+ncost;
        pq.push({-dist[next],next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cin.tie(NULL);
  cin >> N >> E;
  for(int i=0; i<E; i++) {
    int u,v,w;
    cin >> u >> v >> w;
    G[u].push_back(make_pair(v,w));
    G[v].push_back(make_pair(u,w));
  }
  int a,b;
  cin >> a >> b;
  fill(dist,dist+N+1,INF);
  long long root1=0, root2=0;
  dijkstra(1);
  root1 += dist[a];
  root2 += dist[b];
  fill(dist+1,dist+N+1,INF);
  dijkstra(a);
  root1 += dist[b];
  root2 += dist[N];
  fill(dist+1,dist+N+1,INF);
  dijkstra(b);
  root1 += dist[N];
  root2 += dist[a];
  long long result = min(root1,root2);
  if(result >= INF) cout << "-1";
  else cout << result;
}
