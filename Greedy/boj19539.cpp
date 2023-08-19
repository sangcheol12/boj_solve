#include <iostream>
#include <algorithm>
using namespace std;

int tree[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	int n,sum=0,cnt=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tree[i];
		sum += tree[i];
		cnt += tree[i]/2;
	}
	if(sum%3 != 0) cout << "NO\n";
	else {
		sum /= 3;
		if(cnt >= sum) cout << "YES\n";
		else cout << "NO\n";
	}
}
