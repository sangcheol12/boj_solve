#include<iostream>
#include<vector>

using namespace std;

const int MAX_V = 1000;
vector<int> G[MAX_V];

bool visited[1001];

void dfs(int cur) {
	visited[cur] = true;
	for(int nxt : G[cur]) {
		if(!visited[nxt])
			dfs(nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,res=0;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		u--, v--;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			dfs(i);
			res++;
		}
	}
	cout << res << '\n';
}