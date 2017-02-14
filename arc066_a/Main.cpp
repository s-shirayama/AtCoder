#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define MOD 1000000007
using namespace std;
typedef long long int LL;
typedef long double LD;

int N, A;

LL _pow(LL a, LL k) {
	LL res = 1;
	while (k > 0) {
		if (k&1 == 1) res = (res * a) % MOD;
		a = a * a % MOD;
		k >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	priority_queue<int, vector<int>, greater<int> >que;
	REP(i, N, 0) {
		cin >> A;
		que.push(A);
	}

	int a = 1;
	if (N&1 == 1) {
		if (que.top() != 0) {
			cout << "0" << endl;
			return 0;
		}
		que.pop();
		a = 2;
	}
	for (int i = a; i < N; i += 2) {
		int v1 = que.top();
		que.pop();
		int v2 = que.top();
		que.pop();
		if (v1 != i || v2 != i) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << _pow(2, N/2) << endl;

	return 0;
}
