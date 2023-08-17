#include <bits/stdc++.h>
using namespace std;

int n;
int ddang[101][101];
int visited[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y, int r) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(ddang[ny][nx] > r && !visited[ny][nx]) {
            dfs(nx,ny,r);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int cnt, max_cnt=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> ddang[i][j];
    for(int r=0; r<=100; r++) {
        cnt = 0;
        fill(&visited[0][0],&visited[100][100],0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(ddang[i][j] > r && !visited[i][j]) {
                    dfs(j,i,r);
                    cnt++;
                }
            }
        }
        max_cnt = max(max_cnt,cnt);
    }
    cout << max_cnt << '\n';
}