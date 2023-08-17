#include <bits/stdc++.h>
using namespace std;

char campus[610][610];
bool visited[610][610];
int n,m;
int cnt;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int y, int x) {
	if(campus[y][x] == 'P') cnt++;
	visited[y][x] = true;
	for(int i=0; i<4; i++) {
		int cy = y + dir[i][0], cx = x + dir[i][1];
		if(cy < 0 || cy >= n || cx < 0 || cx >= m) continue;
		if(campus[cy][cx] == 'X' || visited[cy][cx]) continue;
		dfs(cy,cx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	pair<int, int> doyeon;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			cin >> campus[i][j];
			if(campus[i][j] == 'I')
				doyeon.first = i, doyeon.second = j;
		}
	dfs(doyeon.first,doyeon.second);
	if(cnt) cout << cnt << '\n';
	else cout << "TT\n";
}