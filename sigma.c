#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG
const int base = 10000; // (base^2) fit into int
const int width = 4; // width = log base
const int N = 50; // n * width: 可表示的最大位数
typedef struct{
	int ln, v[50];
}bint;
bint itob(int r){
	bint re;
	for (re.ln = 0; r > 0; r /= base)  re.v[re.ln++] = r % base;
	return re;
}
int bsmaller (const bint a, const bint b){
	int i;
	if (a.ln != b.ln) return a.ln < b.ln;
	for (i = a.ln - 1; i >= 0 && a.v[i] == b.v[i]; i--);
	return i < 0 ? 0 : a.v[i] < b.v[i];
}
int bnolarger (const bint a, const bint b){
	return !(bsmaller(b, a));
}
bint badd(const bint a, const bint b){
	bint res; int i, cy = 0;
	for (i = 0; i < a.ln || i < b.ln || cy > 0; i++) {
		if (i < a.ln) cy += a.v[i];
		if (i < b.ln) cy += b.v[i];
			res.v[i] = cy % base; cy /= base;
	}
	res.ln = i;
	return res;
}
bint bminus (const bint a, const bint b){
	bint res; int i, cy = 0;
	for (res.ln = a.ln, i = 0; i < res.ln; i++) {
		res.v[i] = a.v[i] - cy;
		if (i < b.ln) res.v[i] -= b.v[i];
		if (res.v[i] < 0) cy = 1, res.v[i] += base;
			else cy = 0;
	}
	while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;
	return res;
}
bint bmultiply (const bint a, const bint b){
	int i, j, cy;
	bint res; res.ln = 0;
	if (0 == b.ln) { res.v[0] = 0; return res; }
	for (i = 0; i < a.ln; i++) {
		for (j=cy=0; j < b.ln || cy > 0; j++, cy/= base) {
			if (j < b.ln) cy += a.v[i] * b.v[j];
			if (i + j < res.ln) cy += res.v[i + j];
			if (i + j >= res.ln) res.v[res.ln++] = cy % base;
			else res.v[i + j] = cy % base;
		}
	}
	return res;
}
bint bdivide (const bint a, const bint b)
{ // ! b != 0
	bint tmp, mod, res;
	int i, lf, rg, mid;
	mod.v[0] = mod.ln = 0;
	for (i = a.ln - 1; i >= 0; i--) {
		mod = badd( bmultiply(mod, itob(base)), itob(a.v[i]));
		for (lf = 0, rg = base -1; lf < rg; ) {
			mid = (lf + rg + 1) / 2;
			if ( bnolarger(bmultiply(b, itob(mid)), mod) ) lf = mid;
			else rg = mid - 1;
		}
		res.v[i] = lf;
		mod = bminus(mod, bmultiply(b, itob(lf)));
	}
	res.ln = a.ln;
	while (res.ln > 0 && res.v[res.ln - 1] == 0) res.ln--;
	return res; // return mod 就是%运算
}
int digits(bint a) // 返回位数
{
	int t, l = ( a.ln - 1 ) * 4;
	if (a.ln == 0) return 0;
	for (t = a.v[a.ln - 1]; t; ++l, t/=10) ;
	return l;
}
void write(const bint v){
	int i;
	printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
	for (i = v.ln - 2; i >= 10; i--)
		printf("%04d", v.v[i]); // ! 4 == width
	printf(".");
	for (i = 9; i >= 7; i--)
		printf("%04d", v.v[i]);
	printf("%02d", (v.v[6] + 50) / 100);
	printf("\n");
}

int k, x, m, n, i;
int ires, itmp, itmp2;
double dres, dtmp, dtmp2;
bint res, bx, btmp, ptmp;

int main()
{
#ifdef DEBUG
#else
	freopen("sigma.in", "r", stdin);
#endif
	scanf("%d%d%d%d", &k, &x, &m, &n);

	res = itob(0);
	ptmp = itob(1);
	for(i=0; i<40; i++)  ptmp = bmultiply(ptmp, itob(10));
	bx = itob(x);

	btmp = ptmp;
	for(i=0; i<=n; i++){
		res = badd(res, btmp);
		btmp = bmultiply(btmp, bx);
	}

	btmp = itob(1);
	for(i=0; i<m; i++){
		btmp = bmultiply(btmp, bx);
		res = badd(res, bdivide(ptmp, btmp));
	}
	res = bmultiply(res, itob(k));

	write(res);

	/*
	ires = 0;  itmp = 1;
	for(i=0; i<=n; i++){
		ires += itmp;
		itmp *= x;
	}

	itmp = 1;  dtmp2 = 0;
	for(i=0; i<m; i++){
		//dtmp2 += dtmp;
		if( itmp > 2147483647 / x )  break;
		itmp *= x;
		dres += (double)k / itmp;
	}

//	dres = (double)(dtmp2) / dtmp;

	ires *= k;
	ires += (int)dres;
	dres -= (int)dres;
	printf("%d%.14lf", ires / 10, dres + ires % 10);
	*/
#ifdef DEBUG
	system("pause");
#endif
	return 0;
}