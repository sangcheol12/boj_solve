#include<iostream>
#include<algorithm>
using namespace std;

pair<int ,int> time[100001];

int cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,use=0,min_s;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> time[i].first >> time[i].second;
	}
	sort(time,time+n);
	sort(time,time+n,cmp);
	min_s = time[0].second;
	use++;
	for(int i=1; i<n; i++) {
		if(time[i].first >= min_s) {
			min_s = time[i].second;
			use++;
		}
	}
	cout << use;
}