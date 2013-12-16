#include<stdio.h>

int prime[]={2,3,5,7,11,13,17,19,23,29};
long long int tmp_div,tmp_num,g[20];

int get_div_num()
{
	int i,n=1;
	for(i=0;g[i]!=0;i++)
		n*=g[i]+1;
	return n;
}

void antiprime(int step,int cur_val,int max_val)
{
	long long int i,k,m,n;
	k=cur_val;
	for(i=1;;i++){
		n=k*prime[step];
		if(n>max_val){
			m=get_div_num();
			if(m>tmp_div||(m==tmp_div&&k<tmp_num)){
				tmp_div=m;
				tmp_num=k;
			}
			return;
		}
		k=n;
		g[step]=i;
		antiprime(step+1,k,max_val);
		g[step+1]=0;
	}
}

int main()
{
	long long int n;
	FILE *in=fopen("antiprime.in","r");
	FILE *out=fopen("antiprime.out","w");
	fscanf(in,"%d",&n);
	//scanf("%d",&n);
	antiprime(0,1,n);
	fprintf(out,"%d",tmp_num);
	//printf("%ld",tmp_num);
	return 0;
}