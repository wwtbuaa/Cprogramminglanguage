#include <stdio.h>
//#include <stdlib.h>

int m, n, p, k;
int i, j, r;
int re[100005], res;

int getre(int t){
	if(t>=0)  return re[t];
	return 0;
}

int main()
{
	scanf("%d%d%d%d", &m, &n, &p, &k);

	re[0] = 1;
	for(i=1; i<=k; i++){
		re[i] = 0;
		for(j=m; j<=n; j++){
			re[i] += getre(i-j);
		}
	}

	res = 0;
	for(i=k; i>=0 && i>k-p; i--)  res += re[i];
	printf("%d\n", res);
	//system("pause");
	return 0;
}