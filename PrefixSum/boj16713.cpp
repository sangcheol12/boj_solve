#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int A[1000101], S[1000101], T;

int main() {
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++)
		scanf("%d",&A[i]);
	for(int i=1; i<=N; i++)
		S[i]=S[i-1]^A[i];
	for(int i=1; i<=M; i++) {
		int L,R;
		scanf("%d %d",&L,&R);
		T^=S[R]^S[L-1];
	}
	printf("%d",T);
}