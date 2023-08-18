#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int A[100101], S[100101];

int main() {
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
		scanf("%d",&A[i]);
	scanf("%d",&M);
	for(int i=1; i<=N; i++)
		S[i]=S[i-1]+A[i];
	while(M--) {
		int L,R;
		scanf("%d %d",&L,&R);
		printf("%d\n",S[R]-S[L-1]);
	}
}