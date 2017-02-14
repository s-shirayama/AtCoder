#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef pair<D, D> P;
int N, T[100001], X[100001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) scanf("%d %d", T+i, X+i);
	D l = 0.0, r = 2.0 * 1e6;
	for (int i = 0; i < 45; i++) {
		D v = (l + r) / 2.0;
		P dp[2];
		int idx = 0;
		dp[idx] = P(0.0, 0.0);
		bool ok = true;
		for (int j = 1; j <= N; j++) {
			idx ^= 1;
			D vt = v * (T[j] - T[j-1]);
			D l1 = X[j-1] - vt, r1 = X[j-1] + vt, l2 = dp[idx^1].first - vt, r2 = dp[idx^1].second + vt;
			bool chk1 = (l1 <= X[j] && X[j] <= r1), chk2 = (l2 <= X[j] && X[j] <= r2);
			if (chk1 && chk2) dp[idx] = P(min(l1, l2), max(r1, r2));
			else if (chk1) dp[idx] = P(l2, r2);
			else if (chk2) dp[idx] = P(l1, r1);
			else {
				ok = false;
				break;
			}
		}
		if (ok) r = v;
		else l = v;
	}
	cout << fixed << setprecision(6) << r << endl;
	return 0;
}