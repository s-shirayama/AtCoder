#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define MOD 1000000007
using namespace std;
typedef long long int LL;

int N, M;

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
	LL res = 1;
	REP(i, n, 0) res = res * (i + 1) % MOD;
	return res;
}

LL nCr(int n, int r) {

	return nPn(n) * _pow(nPn(n-r) * nPn(r) % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cout << nCr(N + M - 2, N - 1) << endl;
}