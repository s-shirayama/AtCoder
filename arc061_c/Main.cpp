// /usr/local/bin/g++ Main.cpp -std=c++14
#include <bits/stdc++.h>

#define INF 4000001
using namespace std;

// Input parameter
int N, M, A, B, C;
// Rosen list
struct edge {int to, co;};
vector<edge> g[100010];
// The shortest distance list @station
int dis[100010];
// Temporary company list @station
set<int> disc[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	// Create Rosen List
	// g[STATION] -> {toStation, Company}
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		g[A].push_back({B, C});
		g[B].push_back({A, C});
	}

	// Initialize distance list (cost list)
	dis[1] = 0;
	for (int i = 2; i <= N; i++) {
		dis[i] = INF;
	}
	// Initialize iteration queue ({distance(cost), station})
	priority_queue<pair<int, int> > q;
	q.push({dis[1], 1});

	// q            : {distance, station}
	// dis[Station] : distance
	// disc[Station]: Company List
	while(q.size()) {
		int now = q.top().second;
		int d = q.top().first;
		q.pop();
		if (dis[now] < d) continue;
		for (edge j : g[now]) {
			int nd = dis[now];
			if (!disc[now].count(j.co)) nd++;
			if (nd < dis[j.to]) {
				dis[j.to] = nd;
				disc[j.to].clear();
				disc[j.to].insert(j.co);
				q.push({dis[j.to], j.to});
			} else if (nd == dis[j.to]) {
				disc[j.to].insert(j.co);
			}
		}
	}

	if (dis[N] == INF) {
		cout << -1 << endl;
	} else {
		cout << dis[N] << endl;
	}
}
