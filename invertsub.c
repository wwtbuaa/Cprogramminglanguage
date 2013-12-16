 
#include<stdio.h>
void reverse(char a[],int n)
{
     int i,t;
     for (i=0;i<=n/2;i++)
     {
         t=a[i];
         a[i]=a[n-i];
         a[n-i]=t;
     }
}

int main()
{
	char s[55],t[55];
	int i,j;
	FILE *in=fopen("invertsub.in","r");
	FILE *out=fopen("invertsub.out","w");
	fgets(s,55,in);
	fgets(t,55,in);
	for(i=0;s[i]!='\n';i++){
		for(j=0;t[j]!='\n';j++)
			if(s[i+j]!=t[j]||s[i+j]=='\n')
				break;
		if(t[j]=='\n'){
			reverse(&s[i],j-1);
			break;
		}
	}
	for(i=0;s[i]!='\n';i++)
		fputc(s[i],out);
	fputc('\n',out);
	return 0;
}