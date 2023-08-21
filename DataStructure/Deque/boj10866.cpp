#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string str; cin >> str;
        if(str == "push_front") {
            int num; cin >> num;
            dq.push_front(num);
        }
        else if(str == "push_back") {
            int num; cin >> num;
            dq.push_back(num);
        }
        else if(str == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << '\n';
                dq.pop_front();
            } else cout << -1 << '\n';
        }
        else if(str == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << '\n';
                dq.pop_back();
            } else cout << -1 << '\n';
        }
        else if(str == "size") cout << dq.size() << '\n';
        else if(str == "empty") cout << dq.empty() << '\n';
        else if(str == "front") {
            if(!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(str == "back") {
            if(!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }
}