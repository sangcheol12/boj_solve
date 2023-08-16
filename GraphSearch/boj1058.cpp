#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

string is_friend[51];
int visited[51];
vector<int> G[51];

void bfs(int st) {
  queue<int> q;
  q.push(st);
  visited[st] = 1;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int nxt : G[cur]) {
      if(!visited[nxt]) {
        q.push(nxt);
        visited[nxt] = visited[cur] + 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,famous=0; cin >> n;
  int cnt[51] = {0};
  for(int i=0; i<n; i++)
    cin >> is_friend[i];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(is_friend[i][j] == 'Y')
        G[i].push_back(j);
  for(int i=0; i<n; i++) {
    bfs(i);
    for(int j=0; j<n; j++) {
      if(visited[j]==2 || visited[j]==3)
        cnt[i]++;
    }
    famous = max(famous,cnt[i]);
    memset(visited,0,sizeof(visited));
  }
  cout << famous;
}
