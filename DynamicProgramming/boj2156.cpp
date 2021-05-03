#include <iostream>
#include <algorithm>
using namespace std;

int score[10001];
int dp[10001][2];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> score[i];
	for(int i=1; i<3; i++) {
		dp[i][0] = score[i];
		dp[i][1] = dp[i-1][0] + score[i];
	}
	for(int i=3; i<=n; i++) {
		dp[i][0] = max({dp[i-3][0],dp[i-3][1],dp[i-2][0],dp[i-2][1]}) + score[i];
		dp[i][1] = dp[i-1][0] + score[i];
	}
	cout << max({dp[n-1][0],dp[n-1][1],dp[n][0],dp[n][1]}) << '\n';
}
//포도주 시식