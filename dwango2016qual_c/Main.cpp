#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 252526
#define INF 100000000
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> PII;

int N, M, SRC, DST, L, S, W;
struct ST {int to, cost, _to, _cost, rosen;};
vector<ST> G[SIZE];
ST RT[SIZE];
int _l[SIZE], _w[SIZE];
int dp[SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> SRC >> DST;
	REP(m, M, 0) {
		cin >> L;
		REP(i, L, 0) cin >> _l[i];
		int w1 = 0, w2 = 0;
		REP(i, L-1, 0) {
			cin >> _w[i];
			w1 += _w[i];
		}
		REP(i, L, 0) {
			if (i > 0) {
				ST s = {_l[i-1], _w[i-1], _l[0], w2, m};
				G[_l[i]].push_back(s);
			}
			if (i < L-1) {
				ST s = {_l[i+1], _w[i], _l[L-1], w1 - w2, m};
				G[_l[i]].push_back(s);
			}
			w2 += _w[i];
		}
	}
	priority_queue<pair<int, int> > que;
	que.push(pair<int, int> (0, SRC));
	fill(dp, dp+SIZE, INF);
	dp[SRC] = 0;
	while (que.size()) {
		pair<int, int> v = que.top();
		que.pop();
		int cost = v.first;
		int s = v.second;
		for (ST st: G[s]) {
			if (dp[st.to] > cost + st.cost) {
				dp[st.to] = cost + st.cost;
				ST _s = {s, 0, st._to, cost + st._cost, st.rosen};
				RT[st.to] = _s;
				que.push(pair<int, int> (dp[st.to], st.to));
			}
		}
	}
	int rosen = -1;
	int res = 0;
	for (int i = DST; i != SRC; i = RT[i].to) {
		cout << i << endl;
		if (rosen != RT[i].rosen) {
			fill(dp, dp+SIZE, INF);
			dp[RT[i]._to] = RT[i]._cost;
			que.push(pair<int, int> (RT[i]._cost, RT[i]._to));
			while (que.size()) {
				pair<int, int> v = que.top();
				que.pop();
				int cost = v.first;
				int s = v.second;
				for (ST st: G[s]) {
					if (dp[st.to] > cost + st.cost) {
						dp[st.to] = cost + st.cost;
						que.push(pair<int, int> (dp[st.to], st.to));
					}
				}
			}
			if (res < dp[DST]) res = dp[DST];
		}
		rosen = RT[i].rosen;
	}
	cout << res << endl;
	return 0;
}
