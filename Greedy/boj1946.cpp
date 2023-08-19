#include <bits/stdc++.h>
using namespace std;

pair<int, int> injae[101010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,cnt;
    cin >> t;
    while (t--)
    {
        cnt = 0;
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> injae[i].first >> injae[i].second;
        sort(injae, injae+n);
        int best_speech = 123456789;
        for(int i=0; i<n; i++) {
            if(best_speech > injae[i].second) {
                cnt++;
                best_speech = injae[i].second;
            }
        }
        cout << cnt << '\n';
    }
}