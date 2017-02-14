#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1 << 30;
const int MAXN = 8;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N >> M;
	vector<int> G[MAXN];
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		G[--A].push_back(--B);
		G[B].push_back(A);
	}
	queue<P> q;
	q.push(P(0, 0));
	int res = 0;
	while(q.size()) {
		int p = q.front().first, c = q.front().second;
		q.pop();
		if (c & (1 << p)) continue;
		c |= (1 << p);
		if (c == (1<<N)-1) {
			res++;
			continue;
		}
		for (int d : G[p]) q.push(P(d, c));
	}
	cout << res << endl;
	return 0;
}