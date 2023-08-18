#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

long long num[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long multi_sum=0,sum=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num[i];
		sum+=num[i];
	}
	for(int i=0; i<n-1; i++) {
		sum-=num[i];
		multi_sum+=sum*num[i];
	}
	cout << multi_sum;
}
// after study