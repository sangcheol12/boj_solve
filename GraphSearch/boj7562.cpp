#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int I;
int dist[301][301];
int dir[8][2] = {{-2,1},{-1,2},{2,1},{1,2},{1,-2},{2,-1},{-1,-2},{-2, -1}};
pair<int,int> loc[2];

void bfs() {
  memset(dist,-1,sizeof(dist));
  queue<pair<int,int>> q;
  q.push(make_pair(loc[0].second,loc[0].first));
  dist[loc[0].second][loc[0].first] = 0;
  while(!q.empty()) {
    int y=q.front().first, x=q.front().second;
    q.pop();
    for(int i=0; i<8; i++) {
      int ny=y+dir[i][1], nx=x+dir[i][0];
      if(ny<0 || ny>=I || nx<0 || nx>=I) continue;
      if(dist[ny][nx] != -1) continue;
      q.push(make_pair(ny,nx));
      dist[ny][nx] = dist[y][x]+1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    cin >> I >> loc[0].first >> loc[0].second >> loc[1].first >> loc[1].second;
    bfs();
    cout << dist[loc[1].second][loc[1].first] << '\n';
  }
}
