#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
int cnt,m_cnt;
vector<int> G[10101];
int visited[10101];
vector<int> res;

void dfs(int cur) {
    visited[cur] = true;
    cnt++;
    for(int nxt : G[cur]) {
        if(visited[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        G[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        cnt = 0;
        fill(visited,visited+n+1,0);
        dfs(i);
        if(cnt > m_cnt) {
            res.clear();
            res.push_back(i);
            m_cnt = cnt;
        } else if(cnt == m_cnt) res.push_back(i);
    }
    sort(res.begin(),res.end());
    for(int v : res) cout << v << ' ';
}