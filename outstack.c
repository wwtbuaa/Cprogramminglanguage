#include <stdio.h>
#include <stdlib.h>


int len=0, s[11];
void push(int a){
	s[len++] = a;
}
int pop(){
	return s[--len];
}
int gettop(){
	return s[len-1];
}

int main()
{
	int l = 0;
	int n, a[11];
	int i, j, num;


	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(i=0; i<n; i++){
		push(i+1);
		while( len > 0  &&  l<n  && gettop() == a[l] ){
			pop();
			l++;
		}
	}
	if( len == 0  &&  l==n )  printf("YES\n");
	else  printf("NO\n");

	return 0;
}