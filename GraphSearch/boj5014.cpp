#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f,s,g,u,d;
int dist[1000001];
bool visited[1000001];
queue<int> q;

void bfs() {
    q.push(s);
    visited[s] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int up = cur + u;
        int down = cur - d;
        if(up <= f && !visited[up]) {
            q.push(up);
            dist[up] = dist[cur]+1;
            visited[up] = true;
        }
        if(down >= 1 && !visited[down]) {
            q.push(down);
            dist[down] = dist[cur]+1;
            visited[down] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    bfs();
    if(visited[g]==0) cout << "use the stairs\n";
    else cout << dist[g] << '\n';
}