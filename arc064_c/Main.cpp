#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = s; i < n; i++)
#define INF 10000000000
using namespace std;

struct BR {double x, y, r;};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	BR b[1002];
	cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> N;
	N += 2;
	REP(i, N, 2) {
		cin >> b[i].x >> b[i].y >> b[i].r;
	}

	using P = pair<double, int>;
	vector<P> G[1002];
	REP(i, N, 0) {
		REP(j, N, i + 1) {
			double dis = max(0.0, sqrt((b[i].x - b[j].x) * (b[i].x - b[j].x) + (b[i].y - b[j].y) * (b[i].y - b[j].y)) - b[i].r - b[j].r);
			G[i].emplace_back(dis, j);
			G[j].emplace_back(dis, i);
		}
	}
	double d[1002];
	fill(d, d + N, INF);
	d[0] = 0.0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.emplace(0.0, 0);
	while (que.size()) {
		double dis = que.top().first;
		int c = que.top().second;
		que.pop();
		if (dis > d[c]) continue;
		for (P p : G[c]) {
			if (d[p.second] > d[c] + p.first) {
				d[p.second] = d[c] + p.first;
				que.emplace(d[p.second], p.second);
			}
		}
	}
	cout << fixed << setprecision(12) << d[1] << endl;

	return 0;
}