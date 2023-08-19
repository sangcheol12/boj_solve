#include <bits/stdc++.h>
using namespace std;

int candy[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, sum=0, less=1001, hol_n=0; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> candy[i];
        sum += candy[i];
        if(candy[i]%2) {
            hol_n++;
            less = min(less,candy[i]);
        }
    }
    if(hol_n%2) sum -= less;
    cout << sum <<'\n';
}