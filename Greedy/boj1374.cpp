#include <bits/stdc++.h>
using namespace std;

pair<int, int> classTime[201010];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,trashNum; cin >> n;
    for(int i=0; i<n; i++)
        cin >> trashNum >> classTime[i].first >> classTime[i].second;
    sort(classTime, classTime+n);
    pq.push(classTime[0].second);
    for(int i=1; i<n; i++) {
        if(pq.top() <= classTime[i].first) pq.pop();
        pq.push(classTime[i].second);
    }
    cout << pq.size() << '\n';
}
