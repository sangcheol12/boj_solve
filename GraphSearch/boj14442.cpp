#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,k;
char map[1001][1001];
int dist[1001][1001][11];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
queue<pair<pair<int,int>,int>> q;

void bfs() {
	while(!q.empty()) {
		int y = q.front().first.first, x = q.front().first.second, z = q.front().second;
		q.pop();
		for(int i=0; i<4; i++) {
			int ny = y+dir[i][0], nx =  x+dir[i][1];
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
      if(map[ny][nx]=='1' && z<k && dist[ny][nx][z+1]==-1) {
				q.push({{ny,nx},z+1});
				dist[ny][nx][z+1] = dist[y][x][z] + 1;
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
	int result = 1234567890;
	cin >> N >> M >> k;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> map[i][j];
			for(int r=0; r<=k; r++)
				dist[i][j][r] = -1;
		}
	}
	q.push({{0,0},0});
	for(int i=0; i<=k; i++)
		dist[0][0][i] = 1;
	bfs();

	for(int i=0; i<=k; i++) {
		if(dist[N-1][M-1][i]!=-1) result = min(result,dist[N-1][M-1][i]);
	}
	if(result == 1234567890) cout << -1;
	else cout << result;
}
