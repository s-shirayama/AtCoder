#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

const int MAXN = 18;

int W[MAXN][MAXN];

int N, K;

LL calc(vector<int> v, int idx, int c) {
	LL res = 0;
	if (idx == N) {
		for (int i = 0; i < N; i++) if ((c >> i) & 1) res += K;
		for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) if (v[i] != v[j]) res -= W[i][j];
		return res;
	}
	bool chk = false;
	for (int i = 0; i <= idx; i++) {
		if ((c>>i)&1 || (((c>>i)&1) == 0 && !chk)) {
			if ((c>>i)&1 == 0) chk = true;
			vector<int> _v;
			copy(v.begin(), v.end(), back_inserter(_v));
			_v.push_back(i);
			res = max(res, calc(_v, idx + 1, c|(1<<i)));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> W[i][j];
	LL res = 0;
	cout << calc(vector<int>(), 0, 0) << endl;
	return 0;
}