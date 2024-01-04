#include <bits/stdc++.h>
using namespace std;

int n,b,c;
long long res;
int num[1010101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) cin >> num[i];
    cin >> b >> c;
    for(int i=0; i<n; i++)
        res += 1+ceil((double)max(num[i]-b,0)/c);
    cout << res << '\n';
}