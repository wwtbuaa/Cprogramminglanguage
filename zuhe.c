#define MAX 20

#include<stdio.h>
#include<stdlib.h>

int answer[MAX];

int generate(int n,int m,int k,int l)
{
	int i;
	if(k==m){
		for(i=0;i<m;i++)
			printf("%d ",answer[i]);
		printf("\n");
	}
	else{
		for(i=l;i<=n-m+k+1;i++){
			answer[k]=i;
			generate(n,m,k+1,i+1);
		}
	}
	return 0;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<m)
		return 0;
	generate(n,m,0,1);
	system("pause");
	return 0;
}