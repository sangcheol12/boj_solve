#include <iostream>
using namespace std;

const int MAX_N = 201;
int par[MAX_N];

void init(int N) {
	for(int i=0; i<N; i++)
		par[i] = i;
}

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	par[x] = y;
}

bool same(int x, int y) {
	x = find(x), y = find(y);
	return x == y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,path[1001] = {0};
	bool is_false=0;
	cin >> n >> m;
	init(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int b;
			cin >> b;
			if(b == 1 && !same(i,j))
				unite(i,j);
		}
	}
	for(int i=0; i<m; i++)
		cin >> path[i];
	for(int i=0; i<m; i++) {
		if(!same(path[0],path[i]-1))
			is_false = 1;
	}
	if(is_false) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}
//여행 가자