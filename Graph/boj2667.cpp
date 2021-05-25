#include <iostream>
#include <algorithm>
using namespace std;

char cmap[26][26];
int imap[26][26];
bool visited[26][26];
int n,headcount[350],t;

int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};

void dfs(int ci, int cj) {
	visited[ci][cj] = true;
	headcount[t]++;
	for(int i=0; i<4; i++) {
		int ni = ci + di[i];
		int nj = cj + dj[i];
		if(ni>=0 && ni<n && nj>=0 && nj<n) {
			if(imap[ni][nj] && !visited[ni][nj]) {
				dfs(ni,nj);
			}
		}
	}
}

int main() {
	int cnt = 0;
	cin >> n;
	for(int i=0; i<n; i++)
		scanf("%s",cmap[i]);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			imap[i][j] = cmap[i][j]-48;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(imap[i][j] && !visited[i][j]) {
				dfs(i,j);
				cnt++;
				t++;
			}
		}
	}
	sort(headcount,headcount+cnt);
	cout << cnt << '\n';
	for(int i=0; i<cnt; i++)
		cout << headcount[i] << '\n';
}
//단지번호붙이기