#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 5*1e3;
const int MAXM = 201;

int main() {
	int N, M, A, B;
	cin >> N >> M;

	LL dp[MAXM][MAXN], t[MAXM][MAXN];
	memset(dp[0], 0, sizeof(dp[0]));
	dp[idx][0] = 0;
	for (int i = 1; i < N; i++) {
		cin >> A;
		dp[0][i] = dp[0][i-1] - A;
	}
	LL _max[MAXM];
	for (int i = 0; i < M; i++) {
		cin >> _max[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
		}
	}

	for (int i = 0; i < N; i++) {
		idx ^= 1;
		memset(dp[idx], 0, sizeof(dp[idx]));
		int _max = 0;
		for (int j = 0; j < M; j++) {
			cin >> B;
			_max = max(_max, B);
			dp[idx][j] = dp[idx^1][j] + _max;
		}
	}
}