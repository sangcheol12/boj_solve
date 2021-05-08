#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> G[1001];
bool visited[1001];

void dfs(int cur) {
	visited[cur] = true;
	cout << cur+1 << ' ';
	for(int nxt : G[cur]) {
		if(!visited[nxt])
			dfs(nxt);
	}
}

void bfs(int st) {
	queue<int> q;
	q.push(st);
	visited[st] = true;
	while(!q.empty()) {
		int cur;
		cur = q.front();
		q.pop();
		cout << cur+1 << ' ';
		for(int nxt : G[cur]) {
			if(!visited[nxt]) {
				q.push(nxt);
				visited[nxt] = true;
			}
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,st;
	cin >> n >> m >> st;
	st--;
	for(int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		u--,v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0; i<n; i++)
		sort(G[i].begin(),G[i].end());
	dfs(st);
	cout << '\n';
	memset(visited,0,sizeof(visited));
	bfs(st);
}