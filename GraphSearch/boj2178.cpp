#include <bits/stdc++.h>
using namespace std;

int miro[101][101];
char temp[101][101];
int visited[101][101];
int n,m;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int>> q;

void bfs(int x, int y) {
    q.push(make_pair(y,x));
    visited[y][x] = 1;
    while (!q.empty())
    {
        int cy = q.front().first, cx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = cy + dir[i][0], nx = cx + dir[i][1];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!miro[ny][nx] || visited[ny][nx]) continue;
            q.push(make_pair(ny,nx));
            visited[ny][nx] = visited[cy][cx] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> temp[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            miro[i][j] = temp[i][j]-'0';
    bfs(0,0);
    cout << visited[n-1][m-1] << '\n';
}