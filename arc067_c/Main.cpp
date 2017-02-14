#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9+7;
const int MAXN = 1e3+1;

LL fact[MAXN];
LL inv[MAXN];

LL _pow(LL a, LL k) {
	LL res = 1;
	while (k) {
		// k%1 == 1
		if (k & 1) res = res * a % MOD;
		a = a * a % MOD;
		// k /= 2;
		k >>= 1;
	}
	return res;
}

int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	// fact[n] : n!
	// inv[n]  : /n!
	fact[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = fact[i-1] * LL(i) % MOD;
		inv[i] = _pow(fact[i], MOD-2);
	}

	LL dp[MAXN][MAXN];
	memset(dp, 0, sizeof(dp));
	dp[A-1][N] = 1;
	for (int i = A; i <= B; i++) {
		for (int j = N; j >= 0; j--) {
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= MOD;
			for (int k = C; k <= D && j-k*i >= 0; k++) {
				// k*i
				// DP[i+1][j-k*i] = DP[i][j] * nCr(j, k*i) / (i!)^k / k!
				dp[i][j-k*i] += ((dp[i-1][j] * (fact[j] * inv[j-k*i] % MOD)) % MOD) * (_pow(inv[i], k) * inv[k] % MOD) % MOD;
			}
		}
	}
	cout << dp[B][0] << endl;
	return 0;
}