#include <iostream>
using namespace std;

const int MAX_N = 1000001;
int par[MAX_N];

void init(int N) {
	for(int i=1; i<=N; i++)
		par[i] = i;
}

int find(int x) {
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	par[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	init(n);
	for(int i=0; i<m; i++) {
		int q,a,b;
		cin >> q >> a >> b;
		if(q==0) unite(a,b);
		else {
			if(same(a,b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}