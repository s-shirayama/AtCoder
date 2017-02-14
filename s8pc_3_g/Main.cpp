#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define MOD 998244353
#define SIZE 400001
using namespace std;
typedef long long int LL;

LL N, M, a[SIZE], npn[SIZE];
LL E[4] = {1,0,0,1};

void mul(LL *a, LL *b) {
	LL res[4];
	memset(res, 0, sizeof(res));
	REP(i, 2, 0) {
		REP(j, 2, 0) {
			REP(k, 2, 0) {
				res[i*2+j] += a[i*2+k] * b[k*2+j];
			}
		}
	}
	memcpy(a, res, sizeof(res));
}

LL _f(int n) {
	LL m[4] = {1,1,1,0}, res[4];
	memcpy(res, E, sizeof(E));

	while (n) {
		if (n & 1) mul(res, m);
		mul(m, m);
		n >>= 1;
	}
	return res[1];
}


LL _pow(LL a, LL k) {
	LL res = 1;
	while (k) {
		if (k & 1) res = res * a % MOD;
		a = a * a % MOD;
		k >>= 1;
	}
	return res;
}

LL nPn(int n) {
	if (npn[n] > 0) return npn[n];
	LL res = 1;
	REP(i, n, 0) {
		res = res * (i + 1) % MOD;
		npn[i+1] = res;
	}
	return res;
}

LL nCr(int n, int r) {
	return nPn(n) * _pow(nPn(n-r) * nPn(r) % MOD, MOD - 2) % MOD;
}

LL calca(LL n) {
	if (a[n] > 0) return a[n];
	a[n] = (calca(n-1) + calca(n-2)) % MOD;
	return a[n];
}

LL calcd(LL n, LL m) {
	LL res = 0;
	for (LL i = 1; i <= m; i++) {
		res = (res + nCr(n + m - 2 - i, n - 2) * calca(i)) % MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(a, 0, sizeof(a));
	memset(npn, 0, sizeof(npn));
	a[1] = 1, a[2] = 1;
	cin >> N >> M;
//	cout << calcd(N, M) << endl;
	cout << _f(N) << endl;
	return 0;
}