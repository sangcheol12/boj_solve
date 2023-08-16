#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct tomato {
    int z, y, x;
};

int map[101][101][101];
int visited[101][101][101];
int dir[6][3] = {{1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
queue<tomato> q;
int m,n,h;

void bfs() {
  while(!q.empty()) {
    int z = q.front().z, y = q.front().y, x = q.front().x;
    q.pop();
    for(int i=0; i<6; i++) {
      int nx = x+dir[i][0], ny = y+dir[i][1], nz = z+dir[i][2];
      //cout << nx << ' ' << ny << ' ' << nz << '\n';
      if(nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h) continue;
      if(map[nz][ny][nx] == -1 || visited[nz][ny][nx] != -1) continue;
      q.push({nz,ny,nx});
      visited[nz][ny][nx] = visited[z][y][x] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> m >> n >> h;
  fill(&visited[0][0][0],&visited[h][n][m],-1);
  for(int i=0; i<h; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++) {
        cin >> map[i][j][k];
        if(map[i][j][k] == 1) {
          q.push({i,j,k});
          visited[i][j][k] = 0;
        }
      }
    }
  }
  bfs();
  int max_day = 0;
  for(int i=0; i<h; i++) {
    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++) {
        if(map[i][j][k] != -1 && visited[i][j][k] == -1) {
          cout << -1 << '\n';
          return 0;
        }
        max_day = max(max_day,visited[i][j][k]);
      }
    }
  }
  cout << max_day << '\n';
}
