#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
const int N = 5000;

typedef long long LL;

double **a, **b, **c;
LL **ha, **hb, **hc;


int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int an, am, bn, bm;
	scanf("%d,%d", &an, &am);
	a = (double**)malloc(sizeof(double*) * an);
	for (int i=0; i<an; ++i) {
		a[i] = (double*)malloc(sizeof(double) * am);
		scanf("%lf", &a[i][0]);
		for (int j=1; j<am; ++j) {
			scanf(",%lf", &a[i][j]);
		}
	}

	scanf("%d,%d", &bn, &bm);
	b = (double**)malloc(sizeof(double*) * bn);
	for (int i=0; i<bn; ++i) {
		b[i] = (double*)malloc(sizeof(double) * bm);
		scanf("%lf", &b[i][0]);
		for (int j=1; j<bm; ++j) {
			scanf(",%lf", &b[i][j]);
		}
	}
	assert(am == bn);
	c = (double**)malloc(sizeof(double) * an);
	for (int i=0; i<an; ++i) {
		c[i] = (double*)malloc(sizeof(double) * bm);
		for (int j=0; j<bm; ++j) {
			c[i][j] = 0;
			// for (int k=0; k<am; ++k) c[i][j] += a[i][k] * b[k][j];
			for (int k=am-1; k>=0; --k) c[i][j] += a[i][k] * b[k][j];
		}
	}
	

	for (int i=0; i<an; ++i) {
		
		for (int j=0; j<bm; ++j)
			printf("%.2lf%c", c[i][j], j==bm-1? '\n':',');
	}
    return 0;
}

