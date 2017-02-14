#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = s; i < n; i++)
#define INF 100000000000
using namespace std;
typedef long long int LL;

struct S {LL min, max;};

S s[100001];
vector<int> G[100001];
int v[100001];

bool func(LL _min, LL _max, int i, int src, int odd) {
	if (s[i].min > _max || s[i].max < _min || ((v[i] > -1) && v[i]%2 != odd)) return false;
	s[i].min = max(s[i].min, _min);
	s[i].max = min(s[i].max, _max);
	for (int p : G[i]) {
		if (p != src) {
			if (!func(s[i].min - 1, s[i].max + 1, p, i, (odd+1)%2)) return false;
			if (s[p].min - 1 > s[i].max || s[p].max + 1 < s[i].min) return false;
			s[i].min = max(s[i].min, s[p].min - 1);
			s[i].max = min(s[i].max, s[p].max + 1);
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, A, B, K, V, P;
	cin >> N;

	fill(v, v+N+1, -1);
	REP(i, N-1, 0) {
		cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	cin >> K;
	int st = 0;
	REP(i, K, 0) {
		cin >> V >> P;
		v[V] = P;
		st = V;
	}
	REP(i, N+1, 1) {
		if (v[i] < 0) {
			s[i] = {-INF, INF};
		} else {
			s[i] = {v[i], v[i]};
		}
	}
	if (func(v[st], v[st], st, 0, v[st]%2)) {
		cout << "Yes" << endl;
		REP(i, N+1, 1) cout << s[i].min << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}