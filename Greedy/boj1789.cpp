#include<iostream>
using namespace std;

int main() {
    int cnt = 0;
    unsigned s;
    cin >> s;
    while(s>cnt) {
        cnt++;
        s-=cnt;
    }
    cout << cnt;
}
