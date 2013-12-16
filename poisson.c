#include <stdio.h>
#include <stdlib.h>

//#define DEBUG
const double E = 2.71828182845904523536028747135266249;

int mm, kk;
double m, k;
int i, j, r;
double res = 1.0;


int main()
{
#ifdef DEBUG
#else
	freopen("poisson.in", "r", stdin);
	freopen("poisson.out", "w", stdout);
#endif

	scanf("%d%d", &mm, &kk);
	m = mm;  k = kk;

	j = 0; r = 1;
	for(i=0; i<kk; i++){
		res *= m;
		if(res > 100000000){
			while(res > 100  &&  j<m){
				res /= E;
				j ++;
			}
			while(res > 100  &&  r<=k){
				res /= (double)r;
				r ++;
			}
		}
	}

	while(j<mm){
		res /= E;
		j ++;
	}
	while(r<=kk){
		res /= (double)r;
		r ++;
	}

	printf("%.6e\n", res);

	
#ifdef DEBUG
	system("pause");
#endif
	return 0;
}