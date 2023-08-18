#include<iostream>
#include<algorithm>
using namespace std;

int n,l,r;
char c,arr[200001];
int cnt[27][200001];

int main() {
	scanf("%s",arr+1);
	scanf("%d",&n);
	for(int j=1; arr[j]; j++) {
		for(int i=0; i<26; i++) {
			cnt[i][j]=cnt[i][j-1];
		}
		cnt[arr[j]-'a'][j]++;
	}
	for(int i=0; i<n; i++) {
		scanf("\n%c %d %d",&c,&l,&r);
		l++;r++;
		printf("%d\n",cnt[c-'a'][r]-cnt[c-'a'][l-1]);
	}
}