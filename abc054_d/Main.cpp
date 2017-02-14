#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1 << 30;
const int MAXN = 400;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, MA, MB, A, B, C;
	cin >> N >> MA >> MB;

	int dp[2][MAXN][MAXN], idx = 0;
	for (int i = 0; i < MAXN; i++) fill(dp[idx][i], dp[idx][i]+MAXN, INF);
	dp[idx][0][0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A >> B >> C;
		idx ^= 1;
		memcpy(dp[idx], dp[idx^1], sizeof(dp[idx^1]));
		for (int j = 0; j < MAXN; j++) for (int k = 0; k < MAXN; k++) if (dp[idx^1][j][k] < INF) {
			dp[idx][j+A][k+B] = min(dp[idx][j+A][k+B], dp[idx^1][j][k] + C);
		}
	}
	int res = INF;
	for (int i = 1; i < MAXN; i++) for (int j = 1; j < MAXN; j++) if (i * MB == j * MA) res = min(res, dp[idx][i][j]);
	if (res == INF) res = -1;
	cout << res << endl;
	return 0;
}