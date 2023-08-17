#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visited[100001];
int s,e;

void bfs() {
  queue<int> q;
  q.push(s);
  visited[s] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur+1 < 100001 && visited[cur+1] == -1) {
      q.push(cur+1);
      visited[cur+1] = visited[cur]+1;
    }
    if(cur-1 >= 0 && visited[cur-1] == -1) {
      q.push(cur-1);
      visited[cur-1] = visited[cur]+1;
    }
    if(cur*2 < 100001 && visited[cur*2] == -1) {
      q.push(cur*2);
      visited[cur*2] = visited[cur]+1;
    }
    if(cur+1 == e || cur-1 == e || cur*2 == e)
      return ;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  fill(visited,visited+100001,-1);
  cin >> s >> e;
  bfs();
  cout << visited[e];
}
