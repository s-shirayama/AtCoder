#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

int N;
LL K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	LL pre = 1000000000;
	while (--N) {
		cin >> K;
		if (pre > K) cout << K << " ";
		else cout << pre << " ";
		pre = K;
	}
	cout << pre << endl;
	return 0;
}
