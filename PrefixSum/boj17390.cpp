#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int A[300101], S[300101], B[300101];

int main() {
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++) {
		scanf("%d",&A[i]);
		B[i]=A[i];
	}
	sort(B+1,B+N+1);
	for(int i=1; i<=N; i++)
		S[i]=S[i-1]+B[i];
	while(M--) {
		int L,R;
		scanf("%d %d",&L,&R);
		printf("%d\n",S[R]-S[L-1]);
	}
}