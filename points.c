#include <stdio.h>

double x[20], y[20];
double res = 0;

int main()
{
	int i = 0, n = 0;
	while( scanf("%lf%lf", &x[n], &y[n]) != EOF ) {
		n ++;
	}

	for(i=1; i<n; i++){
		res += x[i] * y[i-1] - x[i-1] * y[i];
	}
	res += x[0] * y[n-1] - x[n-1] * y[0];

	if(res < 0)   res = -res;
	printf("%.2lf", res/2);
	
	return 0;
}