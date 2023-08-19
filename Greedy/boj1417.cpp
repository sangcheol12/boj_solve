#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rate[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,max_rate,best,still=0;
	cin >> n;
	for(int i=1; i<n+1; i++)
		cin >> rate[i];
	while(1) {
		best=1;
		max_rate=rate[1];
		for(int i=2; i<n+1; i++) {
			if(rate[i]>=max_rate) {
				best=i;
				max_rate=rate[i];
			}
		}
		if(best==1)
			break;
		rate[best]--;
		rate[1]++;
		still++;
	}
	cout << still;
}