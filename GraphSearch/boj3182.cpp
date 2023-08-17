#include <bits/stdc++.h>
using namespace std;

vector<int> G[1001];
int visited[1001];
int cnt;

void dfs(int cur) {
  visited[cur] = 1;
  cnt++;
  for(int nxt : G[cur])
    if(!visited[nxt])
      dfs(nxt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,max_cnt=0,res=0; cin >> n;
    for(int i=0; i<n; i++) {
      int j; cin >> j;
      j--;
      G[i].push_back(j);
    }
    for(int i=0; i<n; i++) {
      cnt = 0;
      fill(visited,visited+n,0);
      dfs(i);
      if(cnt > max_cnt) {
        res = i+1;
        max_cnt = cnt;
      }
    }
    cout << res << '\n';
}
