#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1e3+1;
const int MOD = 1e9+7;

int main() {
	int N;
	cin >> N;
	int n[MAXN];
	memset(n, 0, sizeof(n));
	for (int i = 2; i <= N; i++) {
		int _i = i;
		for (int j = 2; j <= i;) {
			if (_i <= 1) break;
			if (_i%j == 0) {
				n[j]++;
				_i /= j;
			} else {
				j++;
			}
		}
	}
	LL ans = 1;
	for (int i = 2; i <= N; i++) {
		if (n[i] > 0) {
			ans *= (n[i] + 1);
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
