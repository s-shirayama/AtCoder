#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

set<LL> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL H, W, N, R, C;
	cin >> H >> W >> N;
	LL res = (H-1)*W + (W-1)*H;
	for (int i = 0; i < N; i++) {
		cin >> R >> C;
		R--, C--;
		if (R > 0   && s.count((R-1)*W+C) == 0) res--;
		if (R < H-1 && s.count((R+1)*W+C) == 0) res--;
		if (C > 0   && s.count(R*W+C-1) == 0) res--;
		if (C < W-1 && s.count(R*W+C+1) == 0) res--;
		s.insert(R*W+C);
	}
	cout << res << endl;

	return 0;
}