#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
char map[1001][1001];
int dist[1001][1001][2];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
queue<pair<pair<int,int>,int>> q;

void bfs() {
	while(!q.empty()) {
		int y = q.front().first.first, x = q.front().first.second, z = q.front().second;
		q.pop();
		for(int i=0; i<4; i++) {
			int ny = y+dir[i][0], nx =  x+dir[i][1];
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
      if(map[ny][nx]=='1' && z==0 && dist[ny][nx][1]==-1) {
				q.push({{ny,nx},1});
				dist[ny][nx][1] = dist[y][x][z] + 1;
			}
			else if(map[ny][nx]=='0' && dist[ny][nx][z]==-1){
				q.push({{ny,nx},z});
				dist[ny][nx][z] = dist[y][x][z]+1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> map[i][j];
			dist[i][j][0]=-1;
			dist[i][j][1]=-1;
		}
	}
	q.push({{0,0},0});
	dist[0][0][0] = 1;
	bfs();
	if(dist[N-1][M-1][0]==-1 && dist[N-1][M-1][1]==-1) {
		cout << -1;
		return 0;
	}
	if(dist[N-1][M-1][0]==-1) dist[N-1][M-1][0]=1234567890;
	if(dist[N-1][M-1][1]==-1) dist[N-1][M-1][1]=1234567890;
	cout << min(dist[N-1][M-1][0],dist[N-1][M-1][1]);
}
