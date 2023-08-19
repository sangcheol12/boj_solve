#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,sum=0,result=0;
	int pp[1001];
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> pp[i];
	}
	sort(pp,pp+n);
	for(int i=0; i<n; i++) {
		sum+=pp[i];
		result+=sum;
	}
	cout << result;
}