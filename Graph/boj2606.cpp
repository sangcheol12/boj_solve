#include <iostream>
#include <vector>
using namespace std;

vector<int> G[101];
bool visited[101];
int res;

void dfs(int cur) {
	visited[cur] = true;
	for(int nxt : G[cur]) {
		if(!visited[nxt]) {
			dfs(nxt);
			res++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0);
	cout << res;
}