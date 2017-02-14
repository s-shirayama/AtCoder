#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 * 2;
int nPn[MAXN];

int _pow(int a, int k) {
	int res = 1;
	while (k) {
		// k%1 == 1
		if (k & 1) res = LL(res) * a % MOD;
		a = LL(a) * a % MOD;
		// k /= 2;	
		k >>= 1;
	}
	return res;
}

int nCr(int n, int r) {
	// /= A  ->  *= A^M-2
	return LL(nPn[n]) * _pow(LL(nPn[n-r]) * nPn[r] % MOD, MOD - 2) % MOD;
}

int calc(int h1, int w1, int h2, int w2) {
	return nCr((h2 - h1) + (w2 - w1), (h2 - h1));
}

int main() {
	int H, W, A, B;
	scanf("%d %d %d %d", &H, &W, &A, &B);

	nPn[0] = 1;
	REP(i, MAXN+1, 1) nPn[i] = LL(i) * nPn[i-1] % MOD;
	int h = H - A, w = B + 1;
	int res = 0;
	while (h >= 1 && w <= W) {
		res = (LL(res) + LL(calc(1, 1, h, w)) * calc(h, w, H, W)) % MOD;
		h--, w++;
	}

	printf("%d\n", res);

	return 0;
}
