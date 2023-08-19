#include <stdio.h>
int main(void)
{
	int i,n,min_e,max_s;
	scanf("%d",&n);
	int s[n];
	int e[n];
	for(i=0; i<n; i++)
		scanf("%d %d",&s[i],&e[i]);
	
	min_e=e[0];
	for(i=1; i<n; i++)
	{
		if(min_e>e[i])
			min_e=e[i];
	}
	max_s=s[0];
	for(i=1; i<n; i++)
	{
		if(max_s<s[i])
			max_s=s[i];
	}
	if(min_e>=max_s)
		printf("0");
	else
		printf("%d",max_s-min_e);
	return 0;
}