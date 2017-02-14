#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 200001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, S, U, V;
	cin >> N >> M >> S;
//N = 200000, M = 199999, S = 200000;
	vector<int> v[MAXN];
	for (int i = 0; i < M; i++) {
		cin >> U >> V;
	//U = i+1, V = i+2;
		v[U].push_back(V);
		v[V].push_back(U);
	}
	priority_queue<P> q;
	bool visited[MAXN], ans[MAXN];
	memset(visited, 0, sizeof(visited));
	memset(ans, 0, sizeof(ans));
	q.push(P(S, S));
	while(q.size()) {
		int d = q.top().second;
		int cost = min(q.top().first, d);
		q.pop();
		if (visited[d]) continue;
		visited[d] = true;
		ans[d] = (cost == d);
		for (int s : v[d]) q.push(P(cost, s));
	}
	for (int i = 1; i <= N; i++) if (ans[i]) printf("%d\n", i);

	return 0;
}