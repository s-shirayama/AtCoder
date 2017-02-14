#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;
typedef long double LD;
 
const int MOD = 1e9 + 7;
 
int main() {
	int N, C, A[400], B[400];
 /*
	scanf("%d %d", &N, &C);
	REP(i, N, 0) scanf("%d", A+i);
	REP(i, N, 0) scanf("%d", B+i);
 	*/
 	N = 400, C = 1;
	REP(i, N, 0) {
		A[i] = i+1, B[i] = i+1;
	}

	LL dp[2][401], sum[401];;
	int idx = 0;
	memset(dp[idx], 0, sizeof(dp[idx]));
	dp[idx][0] = 1;
 
	REP(i, N, 0) {
		int _idx = idx;
		idx = (idx+1)%2;
		memset(dp[idx], 0, sizeof(dp[idx]));
		REP(k, B[i] + 1, A[i]) {
			sum[0] = dp[_idx][0];
			dp[idx][0] = (dp[idx][0] + sum[0]) % MOD;
			REP(j, C + 1, 1) {
				sum[j] = ((k * sum[j-1]) % MOD + dp[_idx][j]) % MOD;
				dp[idx][j] = (dp[idx][j] + sum[j]) % MOD;
			}
		}
	}
 
	printf("%d\n", dp[idx][C]);
	return 0;
}