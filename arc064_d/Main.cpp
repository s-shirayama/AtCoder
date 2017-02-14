#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define MOD 1000000007
using namespace std;
typedef long long int LL;
typedef long double LD;

LL _pow(LL a, LL k) {
	LL res = 1;
	while (k) {
		if (k&1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		k >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL N, K;
	cin >> N >> K;

	map<int, LL> num;
	REP(i, sqrt(N)+1, 1) {
		if (N%i == 0) {
			num[i] = _pow(K, (i+1)/2);
			int j = N / i;
			num[j] = _pow(K, (j+1)/2);
		}
	}
	for (auto p1 : num) {
		for (auto p2 : num) {
			if (p2.first != p1.first && p2.first % p1.first == 0) {
				num[p2.first] -= num[p1.first];
				num[p2.first] = (num[p2.first] + MOD) % MOD;
			}
		}
	}
	LL res = 0;
	for (auto p : num) {
		res = (res + p.second * p.first / (1 + !(p.first&1))) % MOD;
	}
	cout << res << endl;
	return 0;
}
