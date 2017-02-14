// 12:31 -> 14:04 = 1h33min
#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 401;
const int MAXC = 401;
const int MAXA = 401;

int main() {
	int N, C, A[MAXN], B[MAXN];
/*
	scanf("%d %d", &N, &C);
	REP(i, N+1, 1) scanf("%d", A+i);
	REP(i, N+1, 1) scanf("%d", B+i);
*/
	N = 400, C = 1;
	REP(i, N+1, 1) {
		A[i] = i, B[i] = i;
	}

	LL Sum[MAXA][MAXC], Pow[MAXA][MAXC];
	REP(i, MAXA, 1) {
		Pow[i][0] = 1;
		REP(j, MAXC, 1) {
			Pow[i][j] = (Pow[i][j-1] * i) % MOD;
		}
	}
	REP(i, MAXC, 0) {
		REP(j, MAXN, 1) {
			Sum[j][i] = (Sum[j-1][i] + Pow[j][i]) % MOD;
		}
	}

/*
	LL dp[2][401];
	int idx = 0;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 1;
*/
	LL dp[MAXN][MAXC];

	dp[0][0] = 1;
	REP(i, N+1, 1) {
/*
		int _idx = idx;
		idx = (idx+1)%2;
		memset(dp[idx], 0, sizeof(dp[idx]));
*/
		REP(j, C+1, 0) {
			REP(k, j+1, 0) {
//				dp[idx][j] = (dp[idx][j] + dp[_idx][k] * ((Sum[B[i]][j-k] - Sum[A[i] - 1][j-k]) % MOD)) % MOD;
				dp[i][j] = (dp[i][j] + dp[i-1][k] * (Sum[B[i]][j-k] - Sum[A[i]-1][j-k]) % MOD) % MOD;
			}
		}
	}

	printf("%d\n", (dp[N][C] + MOD) % MOD);
	return 0;
}
