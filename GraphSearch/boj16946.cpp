#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int field[1001][1001];
int visited[1001][1001];
vector<int> v;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m,cnt,group_n=1;

void dfs(int y, int x) {
    visited[y][x] = group_n;
    cnt++;
    for(int i=0; i<4; i++) {
        int ny=y+dir[i][0], nx=x+dir[i][1];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(field[ny][nx] || visited[ny][nx]) continue;
        dfs(ny,nx);
    }
}

int groupSize(int y, int x) {
    int ret = 1;
    set<int> s;
    for(int i=0; i<4; i++) {
        int ny=y+dir[i][0], nx=x+dir[i][1];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        s.insert(visited[ny][nx]);
    }
    for(int i : s) ret += v[i];
    return ret;
}

int main(void){
    v.push_back(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d",&field[i][j]);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cnt=0;
            if(field[i][j] || visited[i][j]) continue;
            dfs(i,j);
            v.push_back(cnt);
            group_n++;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(field[i][j]) cout << groupSize(i,j)%10;
            else cout << 0;
        }
        cout << '\n';
    }
}