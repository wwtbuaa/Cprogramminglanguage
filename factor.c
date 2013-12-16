#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//#define DEBUG

int i, j, n, s[1005], l, tmp, tmp2;

int main()
{
#ifdef DEBUG
	while (1)
	{
#else
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(i=0; i<1000; i++){
		s[i] = 0;
	}
	s[0] = 1;  l = 1;

	for(i=1; i<=n; i++){
		tmp = s[0] * i; s[0] = 0;
		for(j=0; j<l; j++){
			s[j] += tmp % 10;
			tmp2 = s[j + 1] * i;
			s[j + 1] = tmp / 10;
			tmp = tmp2;
		}
		for(j=0; j<l; j++){
			s[j + 1] += s[j] / 10;
			s[j] %= 10;
		}
		while(s[l]){
			s[l + 1] = s[l] / 10;
			s[l] %= 10;
			l++;
		}
	}
	for(i=l-1; i>=0; i--){
		printf("%d", s[i]);
		if((l-i)%50 == 0)  printf("\n");
	}
#ifdef DEBUG
	printf("\n");
}
#else
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}