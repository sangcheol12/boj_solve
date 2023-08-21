#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) q.push(i);
    for(int i=0; i<n-1; i++) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << '\n';
}