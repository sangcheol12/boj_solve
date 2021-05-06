#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool map[51][51];
bool visited[51][51];
int di[] = {0,0,-1,1};
int dj[] = {-1,1,0,0};
int M,N;

void dfs(int ci,int cj) {
	visited[ci][cj] = true;
	for(int d=0; d<4; d++) {
		int ni = ci + di[d];
		int nj = cj + dj[d];
		if(0<=ni && ni<N && 0<=nj && nj<M) {
			if(map[ni][nj] && !visited[ni][nj]) {
				dfs(ni,nj);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,k,x,y,count;
	cin >> t;
	while(t--) {
		count = 0;
		cin >> N >> M >> k;
		for(int i=0; i<k; i++) {
			cin >> x >> y;
			map[x][y] = true;
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(map[i][j] && !visited[i][j]) {
					dfs(i,j);
					count++;
				}
			}
		}
		cout << count << '\n';
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
	}
}
//유기농 배추