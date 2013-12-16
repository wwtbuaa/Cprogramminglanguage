#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int p){
	int i = p/2, j;
	if( p & 1 ){
		for(j=3; j<=i; j+=2){
			if( p % j == 0 )  return 0;
		}
		return 1;
	}
	return 0;
}

int n, i, j, k;
int p[2][100000], l[2];
int main()
{
	scanf("%d", &n);

	l[0] = 4;
	p[0][0] = 2;
	p[0][1] = 3;
	p[0][2] = 5;
	p[0][3] = 7;

	for(i=2; i<=n; i++){
		l[(i+1)%2] = 0;
		for(j=0; j<l[i%2]; j++){
			for(k=1;  k<10; k+=2){
				if( isPrime( p[i%2][j] * 10 + k ) ){
					p[(i+1)%2][ l[(i+1)%2] ++ ] = p[i%2][j] * 10 + k;
				}
			}
		}
	}

	for(j=0; j<l[(n+1)%2]; j++){
		printf("%d\n", p[(n+1)%2][j]);
	}

	//system("pause");
	return 0;
}