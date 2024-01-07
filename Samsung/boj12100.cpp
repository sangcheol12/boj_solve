#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,res;

int findBiggest(vector<vector<int> > new_map) {
    int ret=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ret = max(ret, new_map[i][j]);
    return ret;
}

vector<vector<int> > mvLeft(vector<vector<int> > new_map) {
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++)
            if(new_map[i][j]) temp.push_back(new_map[i][j]);
        if(temp.empty()) continue;
        for(int j=0; j<temp.size()-1; j++)
            if(temp[j]==temp[j+1]) { temp[j]*=2; temp[j+1]=0; }
        fill(new_map[i].begin(), new_map[i].end(), 0);
        int idx=0;
        for(int j=0; j<temp.size(); j++)
            if(temp[j]) new_map[i][idx++] = temp[j];
    }
    return new_map;
}

vector<vector<int> > mvRight(vector<vector<int> > new_map) {
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=n-1; j>=0; j--)
            if(new_map[i][j]) temp.push_back(new_map[i][j]);
        if(temp.empty()) continue;
        for(int j=0; j<temp.size()-1; j++)
            if(temp[j]==temp[j+1]) { temp[j]*=2; temp[j+1]=0; }
        fill(new_map[i].begin(), new_map[i].end(), 0);
        int idx=n-1;
        for(int j=0; j<temp.size(); j++)
            if(temp[j]) new_map[i][idx--] = temp[j];
    }
    return new_map;
}

vector<vector<int> > mvUp(vector<vector<int> > new_map) {
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<n; j++)
            if(new_map[j][i]) temp.push_back(new_map[j][i]);
        if(temp.empty()) continue;
        for(int j=0; j<temp.size()-1; j++)
            if(temp[j]==temp[j+1]) { temp[j]*=2; temp[j+1]=0; }
        for(int j=0; j<n; j++) new_map[j][i]=0;
        int idx=0;
        for(int j=0; j<temp.size(); j++)
            if(temp[j]) new_map[idx++][i] = temp[j];
    }
    return new_map;
}

vector<vector<int> > mvDown(vector<vector<int> > new_map) {
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=n-1; j>=0; j--)
            if(new_map[j][i]) temp.push_back(new_map[j][i]);
        if(temp.empty()) continue;
        for(int j=0; j<temp.size()-1; j++)
            if(temp[j]==temp[j+1]) { temp[j]*=2; temp[j+1]=0; }
        for(int j=0; j<n; j++) new_map[j][i]=0;
        int idx=n-1;
        for(int j=0; j<temp.size(); j++)
            if(temp[j]) new_map[idx--][i] = temp[j];
    }
    return new_map;
}

void backtracking(int depth, vector<vector<int> > new_map) {
    if(depth==5) {
        res = max(res,findBiggest(new_map));
        return ;
    }
    backtracking(depth+1,mvLeft(new_map));
    backtracking(depth+1,mvRight(new_map));
    backtracking(depth+1,mvUp(new_map));
    backtracking(depth+1,mvDown(new_map));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int> > my_map(25,vector<int>(25));
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> my_map[i][j];
    backtracking(0,my_map);
    cout << res << '\n';
}