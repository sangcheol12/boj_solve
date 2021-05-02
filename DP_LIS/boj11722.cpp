#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,res=0;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> num[i];
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		for(int j=0; j<i; j++) {
			if(num[i] < num[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
		res = max(res,dp[i]);
	}
	cout << res << '\n';
}
//가장 긴 감소하는 부분 순열