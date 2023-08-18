#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num[101010];
int n,s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> num[i];
    int start = 0, end = 0, sum = 0, res = 1234567890;
    while (start <= end) {
		if (sum >= s) {	// 현재 포인터의 합이 s보다 크거나 같으면 start ++
			res = min(res, end - start);	// 가장 짧은 길이만 저장
			sum -= num[start++];
		}
		else if (end == n) break;
		else sum += num[end++];	// end++ 함으로써 sum 증가
	}
    if(res == 1234567890) res = 0;
    cout << res  << '\n';
}