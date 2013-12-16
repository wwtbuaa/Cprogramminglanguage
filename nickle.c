#include<stdio.h>

int main()
{
	int a,i,n;
	scanf("%d",&n);
	n*=100;
	a=0;
	for(i=0;5*i<=n;i++)
		a+=(n-5*i)/2+1;
	printf("%d",a);
	return 0;
}