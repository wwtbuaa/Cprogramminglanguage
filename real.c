#include<stdio.h>
#include<string.h>


int check_decimal(char s[])
{
	int i,l,n=0;
	l=strlen(s);
	if(s[0]=='-'&&s[1]=='0'&&s[2]=='\0')
		return -1;
	if(s[0]=='-'||s[0]=='+'){
		for(i=1;i<=l;i++)
			s[i-1]=s[i];
		l=strlen(s);
	}
	if(l==0)
		return -1;
	for(i=0;i<l;i++){
		if(s[i]=='.'||(s[i]>='0'&&s[i]<='9')){
		}
		else
			return -1;
	}
	if(s[0]=='0'&&s[1]!='.'&&s[1]!='\0')
		return -1;
	for(i=0;i<l;i++)
		if(s[i]=='.')
			n++;
	if(n>1)
		return -1;
	if(s[0]=='.'||s[l-1]=='.')
		return -1;
	return 1;
}

int check_sci(char s[])
{
	int i,l;
	l=strlen(s);
	if(s[0]=='-'||s[0]=='+'){
		for(i=1;i<=l;i++)
			s[i-1]=s[i];
		l=strlen(s);
	}
	if(l==0)
		return -1;
	for(i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
		}
		else
			return -1;
	}
	return 1;
}

int main()
{
	char s[2000];
	int i,l;
	int e=-1;
	FILE *in=fopen("real.in","r");
	FILE *out=fopen("real.out","w");
	//fgets(s,2000,in);
	fscanf(in,"%s",s);
	l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]=='E'||s[i]=='.'||s[i]=='+'||s[i]=='-'||(s[i]>='0'&&s[i]<='9')){
		}
		else{
			fprintf(out,"Wrong\n");
			return 0;
		}
	}
	for(i=0;i<l;i++){
		if(s[i]=='E'){
			if(e==-1)
				e=i;
			else{
				fprintf(out,"Wrong\n");
				return 0;
			}
		}
	}
	if(e==-1){
		if(check_decimal(s)==1)
			fprintf(out,"Format1\n");
		else
			fprintf(out,"Wrong\n");
	}
	else{
		s[e]='\0';
		if(check_decimal(s)==1&&check_sci(&s[e+1])==1)
			fprintf(out,"Format2\n");
		else
			fprintf(out,"Wrong\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}