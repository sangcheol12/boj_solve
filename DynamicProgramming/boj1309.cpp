#include <iostream>
using namespace std;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[1]=3,dp[2]=7;
	for(int i=3; i<=n; i++)
		dp[i] = 2*(dp[i-1]%9901) + dp[i-2]%9901;
	cout << dp[n]%9901 << '\n';
}
//동물원