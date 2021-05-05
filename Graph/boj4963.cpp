#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[51][51];
bool visited[51][51];

int di[] = {-1,1,0,0,-1,-1,1,1};
int dj[] = {0,0,-1,1,-1,1,-1,1};
int W,H;

void dfs(int ci,int cj) {
	visited[ci][cj] = true;
	for(int d=0; d<8; d++) {
		int ni = ci + di[d];
		int nj = cj + dj[d];
		if(ni>=0 && ni<H && nj>=0 && nj<W) {
			if(map[ni][nj]==1 && !visited[ni][nj])
				dfs(ni,nj);
		}
	}
}

int main() {
	int count;
	while(1) {
		count=0;
		cin >> W >> H;
		if(W==0 && H==0)
			break;
		for(int i=0; i<H; i++)
			for(int j=0; j<W; j++)
				cin >> map[i][j];
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				if(map[i][j]==1 && !visited[i][j]) {
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