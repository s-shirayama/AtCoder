#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;

LL N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	LL res;
	if (N & 1) res = N + 1;
	else res = N - 1;
	cout << res << endl;

	return 0;
}