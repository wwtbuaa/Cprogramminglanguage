#include <stdio.h>
#include <stdlib.h>

int a[200005], b[200005], i, n, n2;
int num, time[1200005] = {0};

int comp(const void *_a, const void *_b){
	return *((int*)_a) - *((int*)_b);
}

int main()
{
	n = 0;
	while( scanf("%d", &a[n]) != EOF ){
		b[n] = a[n];
		n++;
	}
	qsort(b, n, sizeof(int), comp);

	n2 = 1;
	for(i=1; i<n; i++){
		if(b[i] != b[i-1]){
			b[n2 ++] = b[i];
		}
	}
	
	for(i=0; i<n; i++){
		printf(" %d", (((int *)bsearch(&a[i], b, n2, sizeof(int), comp)) - b) + 1 ); 
	}
	return 0;
}