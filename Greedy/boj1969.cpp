#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;
string str[1001];
char res[51];
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> str[i];
    for(int i=0; i<m; i++) {
        int DNA[4] = {0}; // A,C,G,T 순서
        for(int j=0; j<n; j++) {
            if(str[j][i] == 'A') DNA[0]++;
            else if(str[j][i] == 'C') DNA[1]++;
            else if(str[j][i] == 'G') DNA[2]++;
            else DNA[3]++;
        }
        int c=0;
        if(c<DNA[0]) {res[i] = 'A'; c = DNA[0];}
        if(c<DNA[1]) {res[i] = 'C'; c = DNA[1];}
        if(c<DNA[2]) {res[i] = 'G'; c = DNA[2];}
        if(c<DNA[3]) {res[i] = 'T'; c = DNA[3];}
        cnt += n-c;
    }
    cout << res << '\n' << cnt << '\n';
}