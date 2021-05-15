#include <iostream>
using namespace std;

bool visited[501];
bool map[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,cnt=0;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		u--,v--;
		map[u][v] = true;
		map[v][u] = true;
	}
	for(int i=1; i<n; i++) {
		if(map[0][i]) {
			visited[i] = true;
			for(int j=1; j<n; j++) {
				if(map[i][j])
					visited[j] = true;
			}
		}
	}
	for(int i=1; i<n; i++)
		if(visited[i])
			cnt++;
	cout << cnt << '\n';
}
//결혼식