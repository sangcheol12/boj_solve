#include <iostream>
#include <algorithm>
using namespace std;

int num[201];
int dp[201];

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
			if(num[j] < num[i])
				dp[i] = max(dp[i],dp[j]+1);
		}
		res = max(res,dp[i]);
	}
	cout << n-res << '\n';
}
//줄세우기