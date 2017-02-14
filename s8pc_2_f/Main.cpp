#include <bits/stdc++.h>
#define REP(i, n, s) for(LL i = (s); i < (n); i++)
#define MOD 1000000007
#define SIZE 100001
using namespace std;
typedef long long int LL;

int A, B, C;
LL P1[SIZE], P2[SIZE];

LL _pow(LL a, LL k) {
	LL res = 1;
	while(k) {
		if (k & 1) res = res * a % MOD;
		a = a * a % MOD;
		k >>= 1;
	}
	return res;
}

// 0 => A - 1
LL nPn(LL n) {
	return P1[n];
}

// C-1 + 0 => (C-1) + A - 1
LL _nPn(LL n) {
	return P2[n-(C-1)];
}

LL nCr(LL n, LL r) {
	return _nPn(n) * _pow(nPn(n-r) * _nPn(r) % MOD, MOD - 2) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	memset(P1, 0, sizeof(P1));
	memset(P2, 0, sizeof(P2));
	P1[0] = 1;
	P2[0] = 1;
	LL r = 1;
	REP(i, A, 0) {
		r = r * (i + 1) % MOD;
		P1[i+1] = r;
	}
	r = (C > 1) ? _pow(r, C - 2) : 1;
	REP(i, A, 0) {
		r = r * (i + (C-1)) % MOD;
		P2[i] = r;
	}
	if (C == 1) P2[0] = 1;
	LL p = 1;
	LL res = 0;
	while (A) {
		res = (res + p * nCr(A+C-2, C-1)) % MOD;
		A--;
		p = p * B % MOD;
	}
	cout << res << endl;
}