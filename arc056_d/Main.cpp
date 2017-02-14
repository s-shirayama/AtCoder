#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 1000;
const int MAXT = 1001;

LL dp[MAXT];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, T, W[MAXN];
	vector<int> v[MAXT];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> W[i];
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> T;
			v[T/2].push_back(i);
		}
	}

	bool chk[MAXN];
	LL res = 0;
	for (int i = 0; i < MAXT; i++) {
		memset(chk, 0, sizeof(chk));
		LL sum = 0;
		for (int j = i+1; j < MAXT; j++) {
			for (int n : v[j]) {
				if (!chk[n]) {
					chk[n] = true;
					sum += W[n];
				}
			}
			if (dp[j] < dp[i] + sum) dp[j] = dp[i] + sum;
		}
		if (res < dp[i]) res = dp[i];
	}
	cout << res << endl;
	return 0;
}