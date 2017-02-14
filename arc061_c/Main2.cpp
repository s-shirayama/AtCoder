#include <bits/stdc++.h>
using namespace std;

#define INF 4000001

int N, M, A, B, C;
struct edge{int to, co;};
vector<edge> g[100010];
struct station {
	int d;
	set<int> co;
} st[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		g[A].push_back({B, C});
		g[B].push_back({A, C});
	}
	st[1].d = 0;
	for (int i = 2; i <= N; i++) {
		st[i].d = INF;
	}

	priority_queue<pair<int, int> > q;
	q.push({1, 0});
	while (q.size()) {
		int now = q.top().first;
		int d = q.top().second;
		q.pop();
		if (st[now].d < d) continue;
		for (edge j: g[now]) {
			int nd = st[now].d;
			if (!st[now].co.count(j.co)) nd++;
			if (nd < st[j.to].d) {
				st[j.to].d = nd;
				st[j.to].co.clear();
				st[j.to].co.insert(j.co);
				q.push({j.to, nd});
			} else if (nd == st[j.to].d) {
				st[j.to].co.insert(j.co);
			}
		}
	}
	cout << ((st[N].d == INF) ? -1 : st[N].d) << endl;
}