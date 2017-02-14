#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MAXN = 1e5 + 1;
const int LOGV = 17;

int dp[LOGV][MAXN], X[MAXN];

int main() {
	int N, L, i, j, Q, logV;

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", X+i);
	}
	for (logV = 1; (1 << (logV + 1)) <= N; logV++);
	scanf("%d", &L);
	for (i = 1, j = 1; i <= N; i++) {
		while (j <= N && X[j] - X[i] <= L) j++;
		dp[0][i] = j - 1;
	}
	for (i = 1; i <= logV; i++) {
		for (j = 1; j + (1<<i)-1 <= N; j++) {
			dp[i][j] = dp[i-1][dp[i-1][j]];
		}
	}
	scanf("%d", &Q);
	int a, b;
	while (Q--) {
		scanf("%d%d", &a, &b);
		if (a > b) a ^= b ^= a ^= b;
		int step = 0;
		for (i = logV; i >= 0; i--) {
			if (dp[i][a] && dp[i][a] < b) {
				step += 1 << i;
				a = dp[i][a];
			}
		}
		printf("%d\n", step + 1);
	}
	return 0;
}
