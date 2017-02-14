#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MOD = 1e9+7;

map<pair<LL, LL>, LL> memo;

LL func(LL S, LL X) {
	if (S < 0 || X < 0) return 0;
	if (S == 0) return 1;
	if (S == 1) return (X > 0) * 2;
	if (memo.find(make_pair(S, X)) != memo.end()) return memo[make_pair(S, X)];
	return memo[make_pair(S, X)] = (func(S/2, X/2) + func((S-1)/2, (X-1)/2) + func((S-2)/2, X/2)) % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL N;
	cin >> N;
	cout << func(N, N) << endl;

	return 0;
}
