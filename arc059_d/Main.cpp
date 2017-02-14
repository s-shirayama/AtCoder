#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MOD2 = 1e8 * 5 + 4;
const int MAXN = 5002;

int main() {
	int N;
	string S;
	scanf("%d", &N);
	cin >> S;
	int len = S.length();

	LL dp[2][MAXN];
	int idx = 0;
	dp[idx][0] = 1;
	REP(i, N + 1, 1) {
		int _idx = idx;
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		dp[idx][0] = (dp[_idx][0] + dp[_idx][1]) % MOD;
		REP(j, i + 1, 1) {
			dp[idx][j] = (2 * dp[_idx][j-1] + dp[_idx][j+1]) % MOD;
		}
	}
	LL res = dp[idx][len];
	REP(i, len, 0) {
		res = (res * MOD2) % MOD;
	}

	cout << res << endl;

	return 0;
}

/*
int main() {
	int N;
	string S;
	scanf("%d", &N);
	cin >> S;
	int len = S.length();

	LL dp[2][302][302];
	int idx = 0;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0][0] = 1;
	REP(i, N+1, 1) {
		int _idx = idx;
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		dp[idx][0][0] = (dp[_idx][1][1] + dp[_idx][1][0] + dp[_idx][0][0]) % MOD;
		REP(j, i + 1, 1) {
			REP(k, min(j, len) + 1, 0) {
				if (j - 1 > k) {
					dp[idx][j][k] = (dp[_idx][j+1][k] + 2 * dp[_idx][j-1][k]) % MOD;
				} else if (k == j - 1) {
					if (k == len) {
						dp[idx][j][k] = (2 * dp[_idx][j-1][k] + dp[_idx][j+1][k]) % MOD;
					} else {
						dp[idx][j][k] = (dp[_idx][j-1][k] + dp[_idx][j+1][k]) % MOD;
					}
				} else if (k == j) {
					dp[idx][j][k] = (dp[_idx][j+1][k] + dp[_idx][j+1][k+1]) % MOD;
					if (k > 0) {
						dp[idx][j][k] = (dp[idx][j][k] + dp[_idx][j-1][k-1]) % MOD;
					}				
				}
			}
		}
	}
	printf("%d\n", dp[idx][len][len]);

	return 0;
}
*/



