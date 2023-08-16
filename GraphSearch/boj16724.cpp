#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m,cnt;
char field[1001][1001];
int visited[1001][1001];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int y, int x) {
	visited[y][x] = 1;
	int dir_i;
	if(field[y][x] == 'U') dir_i = 0;
	else if(field[y][x] == 'D') dir_i = 1;
	else if(field[y][x] == 'L') dir_i = 2;
	else if(field[y][x] == 'R') dir_i = 3;

	int ny = y + dir[dir_i][0], nx = x + dir[dir_i][1];
	if(visited[ny][nx]==1) cnt++;
	else if(!visited[ny][nx]) dfs(ny,nx);
	visited[y][x] = 2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> field[i][j];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(!visited[i][j])
				dfs(i,j);
	cout << cnt << '\n';
}