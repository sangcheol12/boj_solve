#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[4001][4001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char str1[4001], str2[4001];
	int str_len1, str_len2, res=0;
	cin >> str1 >> str2;
	str_len1 = strlen(str1);
	str_len2 = strlen(str2);
	for(int i=1; i<=str_len1; i++) {
		for(int j=1; j<=str_len2; j++) {
			if(str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				res = max(res,dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	cout << res << '\n';
}
//공통 부분 문자열