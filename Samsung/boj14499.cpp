#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m,x,y,k;
vector<int> dice(7); // 상북동서남하
int my_map[25][25];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

void rollNorth() {
    dice = {0,dice[5],dice[1],dice[3],dice[4],dice[6],dice[2]};
}

void rollWest() {
     dice = {0,dice[3],dice[2],dice[6],dice[1],dice[5],dice[4]};
}

void rollEast() {
     dice = {0,dice[4],dice[2],dice[1],dice[6],dice[5],dice[3]};
}

void rollSouth() {
     dice = {0,dice[2],dice[6],dice[3],dice[4],dice[1],dice[5]};
}

void rolling(int t) {
    switch (t)
    {
    case 1:
        rollEast();
        break;
    case 2:
        rollWest();
        break;
    case 3:
        rollNorth();
        break;
    case 4:
        rollSouth();
        break;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m >> y >> x >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> my_map[i][j];
    for(int i=0; i<k; i++) {
        int d; cin >> d;
        int ny=y+dir[d-1][0], nx=x+dir[d-1][1];
        if(ny>=n || ny<0 || nx<0 || nx>=m) continue;
        y=ny, x=nx;
        rolling(d);
        cout << dice[1] << '\n';
        if(!my_map[y][x]) my_map[y][x]=dice[6];
        else {
            dice[6] = my_map[y][x];
            my_map[y][x] = 0;
        }
    }
}