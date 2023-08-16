#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,r,d;
pair<int,int> field[55];
vector<int> G[55];
int visited[55];

void bfs() {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int nxt : G[cur]) {
      if(visited[nxt]) continue;
      q.push(nxt);
      visited[nxt] = visited[cur]+1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double res = 0;
  cin >> n >> r >> d >> field[0].first >> field[0].second;
  for(int i=1; i<=n; i++) {
    cin >> field[i].first >> field[i].second;
    for(int j=0; j<i; j++) {
      if((field[i].first-field[j].first)*(field[i].first-field[j].first) + (field[i].second-field[j].second)*(field[i].second-field[j].second) <= r*r) {
        G[i].push_back(j);
        G[j].push_back(i);
      }
    }
  }
  bfs();
  for(int i=1; i<=n; i++) {
    if(visited[i])
      res += (double)d/pow(2,(visited[i]-1));
  }
  cout << res << '\n';
}
