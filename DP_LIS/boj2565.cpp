#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> elc[101];
int dp[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,res=1;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> elc[i].first >> elc[i].second;
	sort(elc,elc+n);
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		for(int j=0; j<i; j++) {
			if(elc[j].second < elc[i].second)
				dp[i] = max(dp[i],dp[j]+1);
		}
		res = max(dp[i],res);
	}
	cout << n-res << '\n';
}
//전깃줄