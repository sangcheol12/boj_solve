#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	if (a%5==0)
	{
		printf("%d",a/5);
	} else if (a==4 || a==7){
		printf("%d",-1);
	} else {
		switch(a%5){
			case 1 :
				printf("%d",a/5+1);
				break;
			case 2 :
				printf("%d",a/5+2);
				break;
			case 3 :
				printf("%d",a/5+1);
				break;
			case 4 :
				printf("%d",a/5+2);
				break;
		}
	}
}