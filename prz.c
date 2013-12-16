#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int l, r;
} interval;

int i, j;
interval s[100005];

int cmp(const void *a , const void *b) 
{
	if( ((interval*)a)->l == ((interval*)b)->l){
		return ((interval*)a)->r > ((interval*)b)->r;
	}
	return ((interval*)a)->l > ((interval*)b)->l;
} 

int main()
{
	FILE *fin = fopen("prz.in", "r");
	//FILE *fout = fopen("prz.out", "w");
	int start, end;

	int n = 0;
	freopen("prz.out", "w", stdout);

	while( fscanf(fin, "%d%d", &s[n].l, &s[n].r) != EOF ) {
		n ++;
	}

	qsort(s, n, sizeof(interval), cmp);

	start = s[0].l; end = s[0].r;
	for(i=1; i<n; i++){
		if( s[i].l <= end){
			end = (end > s[i].r) ? end : s[i].r;
		}
		else {
			printf("%d %d\n", start, end);
			start = s[i].l;
			end = s[i].r;
		}
	}
	printf("%d %d\n", start, end);


	fclose(fin);
	fclose(stdout);
	return 0;
}