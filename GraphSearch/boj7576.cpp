#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[1001][1001];
int visited[1001][1001];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
queue<pair<int,int>> q;
int M,N;

void bfs() {
  while(!q.empty()) {
    int y=q.front().first, x=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int ny=y+dir[i][0], nx=x+dir[i][1];
      if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
      if(map[ny][nx]==-1 || visited[ny][nx]!=-1) continue;
      q.push({ny,nx});
      visited[ny][nx]=visited[y][x]+1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int result=0;
  cin >> M >> N;
  fill(visited[0],visited[0]+(sizeof(visited)/sizeof(visited[0][0])),-1);
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> map[i][j];
      if(map[i][j] == 1) {
        q.push({i,j});
        visited[i][j]=0;
      }
    }
  }
  bfs();
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(map[i][j]!=-1 && visited[i][j]==-1) {
        cout << -1;
        return 0;
      }
      result = max(result,visited[i][j]);
    }
  }
  cout << result;
}
