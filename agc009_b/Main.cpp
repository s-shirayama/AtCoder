#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

vector<int> G[MAXN];

int calc(int n) {
	if (G[n].size() == 0) return 0;
	priority_queue<int, vector<int>, greater<int>> q;
	int res = 0;
	for (int s : G[n]) {
		q.push(calc(s));
	}
	while(q.size()) {
		int d = q.top(); q.pop();
		res = max(d, res) + 1;
//		cout << "hoge" << d << ":" << res << endl;
	}
//	cout << n << ":" << res << endl;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, A;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A;
		G[--A].push_back(i);
	}
	cout << calc(0) << endl;

	return 0;
}