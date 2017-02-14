#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL X;
	cin >> X;

	LL res11 = X/LL(11);
	LL res = res11*2LL;
	if (X - res11 * LL(11) > 6) res += 2LL;
	else if (X - res11 * LL(11) > 0) res += 1LL;
	cout << res << endl;
	return 0;
}