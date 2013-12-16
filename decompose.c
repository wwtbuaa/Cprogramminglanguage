#include<stdio.h>

int isprime(int n)
{
	int t,i;
	for(i=2;i<n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	int n,i,j=0,m;
	int p[5000],s[5000];
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		if(isprime(i)){
			p[j++]=i;
		}
	for(i=0;i<j;i++){
		m=p[i];
		s[i]=0;
		while(n/m>0){
			s[i]=s[i]+n/m;
			m=m*p[i];
		}
	}
	for(i=0;i<j;i++){
		printf("%d",p[i]);
		if(s[i]>1)
			printf("^%d",s[i]);
		if(i<j-1)
			printf("*");
		else
			printf("\n");
	}
	return 0;
}