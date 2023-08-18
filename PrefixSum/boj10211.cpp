#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int sum, lm, rm, tm;
};

int N;
int A[100001];

Node dnc(int L, int R) {
	Node ret;
	if(L==R) {
		ret.sum = ret.lm = ret.rm = ret.tm = A[L];
		return ret;
	}
	int mid = (L+R)/2;
	Node Lnode = dnc(L,mid);
	Node Rnode = dnc(mid+1,R);
	ret.sum = Lnode.sum + Rnode.sum;
	ret.lm = max(Lnode.lm, Lnode.sum + Rnode.lm);
	ret.rm = max(Rnode.rm, Rnode.sum + Lnode.rm);
	ret.tm = max({Lnode.tm, Rnode.tm, Lnode.rm + Rnode.lm});
	return ret;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		for(int i=1; i<=N; i++)
			scanf("%d",&A[i]);
		printf("%d\n",dnc(1,N).tm);
	}
}