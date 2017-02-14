#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, A, X[50];
	LL dp[2][51][2501];

	cin >> N >> A;
	REP(i, N, 0) cin >> X[i];

	int idx = 0, _idx;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0][0] = 1;
	REP(i, N, 0) {
		_idx = idx;
		idx = (idx+1)%2;
		memset(dp[idx], 0, sizeof(dp[idx]));
		REP(j, i+2, 0) {
			REP(k, 2501, 0) {
				dp[idx][j][k] = dp[_idx][j][k];
				if (j > 0 && k >= X[i]) dp[idx][j][k] += dp[_idx][j-1][k-X[i]];
			}
		}
	}
	LL res = 0;
	REP(i, N+1, 1) res += dp[idx][i][A*i];
	cout << res << endl;

	return 0;
}