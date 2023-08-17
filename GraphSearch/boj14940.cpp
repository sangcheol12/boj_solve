#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,sy,sx;
int g[1001][1001],dist[1001][1001];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
queue<pair<int,int>> q;

void bfs() {
	memset(dist,-1,sizeof(dist));
	q.push({sy,sx});
	dist[sy][sx] = 0;
	while(!q.empty()) {
		int y=q.front().first, x=q.front().second;
		q.pop();
		for(int i=0; i<4; i++) {
			int ny = y+dir[i][0], nx = x+dir[i][1];
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(g[ny][nx] == 0 || dist[ny][nx] != -1) continue;
			q.push({ny,nx});
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> g[i][j];
			if(g[i][j]==2) {
				sy=i,sx=j;
				g[i][j] = 1;
			}
		}
	}
	bfs();
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if (g[i][j] == 0) cout << "0 ";
			else cout << dist[i][j] << ' ';
		}
		cout << "\n";
	}
}