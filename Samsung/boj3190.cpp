#include <bits/stdc++.h>
using namespace std;

int n,k,l,ticks,v_idx,y,x;
int my_map[105][105];
deque<pair<int, int> > tail;
queue<pair<int, char> > spin;
int v[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    tail.push_back(make_pair(0,0));
    cin >> n >> k;
    for(int i=0; i<k; i++) {
        int a,b; cin >> a >> b;
        my_map[a-1][b-1] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++) {
        int t; char c;
        cin >> t >> c;
        spin.push(make_pair(t,c));
    }
    while (1) {
        ticks++;
        y+=v[v_idx][0]; x+=v[v_idx][1];
        if(y>=n || x>=n || y<0 || x<0) break;
        bool tf = false;
        for(pair<int, int> i : tail)
            if(i.first == y && i.second == x) tf=true;
        if(tf) break;

        if(my_map[y][x]) my_map[y][x]=0;
        else tail.pop_front();
        tail.push_back(make_pair(y,x));
        
        if(!spin.empty() && spin.front().first == ticks) {
            if(spin.front().second=='D') v_idx = (v_idx+1)%4;
            else v_idx = (v_idx+3)%4;
            spin.pop();
        }
    }
    cout << ticks << '\n';
}