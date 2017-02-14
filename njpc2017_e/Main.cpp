#include <bits/stdc++.h>
using namespace std;

struct E {int to, co, di;};
struct F {int a, b, c;};

const int INF = 1 << 30;
const int MAXN = 1e5;

vector<E> G[MAXN];
queue<F> _q;
int N, D, A, B, C;

int bfs(int s, bool *d) {
	int _max = -1, idx = -1;
	_q.push(F{s, 0, -1});
	while (_q.size()) {
		int to = _q.front().a, co = _q.front().b, pre = _q.front().c; _q.pop();
		d[to] &= (co <= D);
		if (co > _max) idx = to;
		for (E e : G[to]) if (e.to != pre) _q.push(F{e.to, co + e.co, to});
	}
	return idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Input
	cin >> N >> D;
	for (int i = 0; i < N-1; i++) {
		cin >> A >> B >> C;
		G[--A].push_back(E{--B, C, 1});
		G[B].push_back(E{A, C, -1});
	}

	// Calucurate diameter
	bool d[MAXN];
	memset(d, true, sizeof(d));
	bfs(bfs(bfs(0, d), d), d);

	// Calculate number of times of reverse
	int cnt = 0, ans = INF;
	_q.push(F{0, 0, -1});
	while(_q.size()) {
		int to = _q.front().a, di = _q.front().b, pre = _q.front().c; _q.pop();
		if (di == 1) cnt++;
		for (E e : G[to]) if (e.to != pre) _q.push(F{e.to, e.di, to});
	}
	_q.push(F{0, cnt, -1});
	while (_q.size()) {
		int to = _q.front().a, ti = _q.front().b, pre = _q.front().c; _q.pop();
		if (d[to] && ans > ti) ans = ti;
		for (E e : G[to]) if (e.to != pre) _q.push(F{e.to, ti - e.di, to});
	}
	cout << ((ans==INF)?-1:ans) << endl;
	return 0;
}
