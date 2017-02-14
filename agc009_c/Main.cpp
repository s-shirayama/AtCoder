#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
const LL INF = 1e18;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	LL A, B, S[MAXN];
	cin >> N >> A >> B;
	// A <= B
	if (A > B) swap(A, B);
//N = 1e4, A = 1, B = 1;
	S[0] = -INF;
	for (int i = 1; i <= N; i++) cin >> S[i];
//for (int i = 1; i <= N; i++) S[i] = i;

	// the last Y is ith
	LL dp[2][MAXN];
	int idx = 0;;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 1;
	dp[idx][1] = 1;
	for (int i = 2; i <= N; i++) {
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		if (S[i] - S[i-1] < A) {
			dp[idx][i-1] = dp[idx^1][i-1];
		} else {
			memcpy(dp[idx], dp[idx^1], sizeof(dp[idx]));
		}
		for (int j = 0; j <= i-1; j++) {
			if (S[i] - S[j] >= B) {
				dp[idx][i] += dp[idx^1][j];
				dp[idx][i] %= MOD;
			}
		}
	}
	LL res = 0;
	for (int i = 0; i <= N; i++) {
		res += dp[idx][i];
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}