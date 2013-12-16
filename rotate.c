#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, n;
	int m[12][12];
	int a, b;
	int nexta[4] = {0, 1, 0, -1}, nextb[4] = {1, 0, -1, 0}, loc;

	scanf("%d", &n);
	for(i=0; i<=n+1; i++){
		for(j=0; j<=n+1; j++){
			m[i][j] = -1;
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			m[i][j] = 0;
		}
	}

	a=1; b=0; loc = 0;
	for(i=1; i<=n*n; i++){
		while( m[ a+nexta[loc] ][ b+nextb[loc] ] != 0 ){
			loc = (loc+1) % 4;
		}
		a += nexta[loc];
		b += nextb[loc];
		m[a][b] = i;
	}

	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
	return 0;
}
