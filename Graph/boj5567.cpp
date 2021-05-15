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
/*결혼식
풀이법 : 인접 행렬
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[501];
int visited[501];

void bfs(int st) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int nxt : G[cur]) {
			if(!visited[nxt]) {
				q.push(nxt);
				visited[nxt] = visited[cur]+1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,cnt=0;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int u,v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs(0);
	for(int i=0; i<n; i++)
		if(visited[i]==2 || visited[i]==3)
			cnt++;
	cout << cnt << '\n';
}
/*결혼식
풀이법 : 인접 리스트(BFS)
*/