#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 3*1e5;
const int MAXM = 1e5+1;

// BIT (Binary indexed tree)
int bit[MAXM];

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i&-i; // i&-i => last bit which is 1.  0110&1010=0010
	}
	return s;
}

void add(int i, int x) {
	while(i <= MAXM) {
		bit[i] += x;
		i += i&-i; // i&-i => last bit which is 1.
	}
}
// BIT : end

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int N, M, L, R;
	vector<pair<int, int>> a[MAXM];
//	cin >> N >> M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
//		cin >> L >> R;
		scanf("%d %d", &L, &R);
		a[R-L+1].push_back(make_pair(L, R));
	}
	for (int i = 1; i <= M; i++) {
		int ans = N;
		for (int j = i; j <= M; j += i) {
			ans += sum(j);
		}
		for (auto p : a[i]) {
			// 001100
			//   LR
			add(p.first, 1);
			add(p.second+1, -1);
			N--;
		}
//		cout << ans << endl;
		printf("%d\n", ans);
	}
	return 0;
}