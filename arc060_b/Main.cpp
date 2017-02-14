#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

LL func(LL b, LL n) {
	if (n < b) return n;
	return func(b, floor(n/b)) + (n % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL N, S;
	cin >> N >> S;



	LL res = -1;
	LL _N = ceil(sqrt((double)N));
	REP(i, _N+1, 2) {
		if (func(i, N) == S && res == -1) {
			res = i;
			break;
		}
	}

	if (res != -1) {
		cout << res << endl;
		return 0;
	}
	for (LL p = _N - 1; p > 0; p--) {
		if (S < p) continue;
		LL q = S - p, b = (N - q) / p;
		if ((N - q)%p == 0 && q < b && b > _N) {
			res = (N - q) / p;
			break;
		}
	}

	if (res == -1 && N == S) {
		cout << (N+1) << endl;
		return 0;
	}

	cout << res << endl;
	return 0;
}
