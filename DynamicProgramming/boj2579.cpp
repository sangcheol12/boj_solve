#include <iostream>
#include <algorithm>
using namespace std;

int score[301];
int dp[301][2];

int main() {
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
		dp[i][0] = max(dp[i-2][0],dp[i-2][1]) + score[i];
		dp[i][1] = dp[i-1][0] + score[i];
	}
	cout << max(dp[n][0],dp[n][1]);
}