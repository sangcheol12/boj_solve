#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int before[31][31];
int after[31][31];
bool visited[31][31];
int N,M;

int dfs(int y,int x) {
  int e;
  visited[y][x] = true;
  for(int i=0; i<4; i++) {
    int ny=y+dir[i][0], nx=x+dir[i][1];
    if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
    if(before[ny][nx]!=before[y][x] || visited[ny][nx]) continue;
    if(after[ny][nx]!=after[y][x]) return 1;
    visited[ny][nx] = true;
    e=dfs(ny,nx);
    if(e==1) return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cnt=0,e=0;
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> before[i][j];
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> after[i][j];
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(before[i][j] != after[i][j]) {
        if(!visited[i][j]) {
          e=dfs(i,j);
          if(e==1) {
            cout << "NO";
            return 0;
          }
          cnt++;
        }
      }
    }
  }
  if(cnt<2) cout << "YES";
  else cout << "NO";
}
