#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int>> q;
int map[51][51];
int visited[51][51];
int n,m;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void bfs() {
  while(!q.empty()) {
    int y = q.front().first; int x = q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int ny = y + dir[i][0]; int nx = x + dir[i][1];
      if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
      if(map[ny][nx] && visited[ny][nx] == -1) {
        q.push({ny,nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }
}

int findMax() {
  int result=0;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      result = max(result,visited[i][j]);
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  char c;
  int result=0;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> c;
      if(c == 'W')
        map[i][j] = 0;
      else
        map[i][j] = 1;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      fill(visited[0], visited[0]+sizeof(visited)/sizeof(visited[0][0]), -1);
      if(map[i][j]) {
        q.push({i,j});
        visited[i][j] = 0;
        bfs();
        result = max(result,findMax());
      }
    }
  }
  cout << result << '\n';
}
