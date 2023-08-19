#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int x,y; cin >> x >> y;
    if(n==1) cout << "0\n";
    else if((x==1 || x==n) && (y==1 || y==n)) cout << "2\n";
    else if((x==1 || x==n) || (y==1 || y==n)) cout << "3\n";
    else cout << "4\n";
}