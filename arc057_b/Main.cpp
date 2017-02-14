#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 2001;
const int INF = 1 << 30;

int main() {
	int N, K;
	int A[MAXN], S[MAXN];
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	S[0] = A[0];
	for (int i = 1; i < N; i++) S[i] = S[i-1] + A[i];
	if (S[N-1] == K) {
		cout << 1 << endl;
		return 0;
	}
	LL dp[2][MAXN];
	int idx = 0;
	fill(dp[0], dp[0] + N + 1, INF);
	dp[0][0] = 0;
	dp[0][1] = 1;
	for (int i = 1; i < N; i++) {
		idx ^= 1; 
		fill(dp[idx], dp[idx] + MAXN, INF);
		dp[idx][0] = 0;
		for (int j = 0; j <= i; j++) {
			dp[idx][j] = min(dp[idx][j], dp[idx^1][j]);
			LL d = dp[idx^1][j] * S[i] / S[i-1] + 1;
			if (d - dp[idx^1][j] <= A[i]) {
				dp[idx][j+1] = min(dp[idx][j+1], d);
			}
		}
	}
	int res = 0;
	for (int i = 0; i <= N; i++) if (dp[idx][i] <= K) res = i;
	cout << res << endl;
	return 0;
}