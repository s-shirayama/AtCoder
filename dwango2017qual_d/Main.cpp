#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 100001
using namespace std;
typedef long long int LL;
typedef long double LD;

int N, M, Y, X;
LL YY[SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	LL sum = 0;
	priority_queue<pair<int, int>> que, que2;
	REP(i, N, 0) {
		cin >> X >> Y;
		sum += Y;
		YY[i] = sum;
		que.push(pair<int, int>(X - Y, i));
	}

	LL res = YY[N-1];
	if (N <= M) {
		while(que.size()) {
			res += que.top().first;
			que.pop();
		}
		cout << res << endl;
		return 0;
	}
	int idx = -1;
	REP(i, M - 1, 0) {
		res += que.top().first;
		idx = max(idx, que.top().second);
		que.pop();
	}
	if (idx == N - 1) {
		res += que.top().first;
		cout << res << endl;
		return 0;
	}
	while (que.size()) {
		pair<int, int> v = que.top();
		que.pop();
		if (v.first > YY[N-1] - YY[max(idx, v.second)]) {
			que2.push(pair<int, int>(v.first - (YY[N-1] - YY[max(idx, v.second)]), v.second));
		}
	}
	if (que2.size()) {
		res += que2.top().first;
	}
	cout << res << endl;

	return 0;
}

/*
int N, M, Y, X;
LL dp[2][SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

//	cin >> N >> M;
	N = 10000;
	M = 10000;

	int idx = 1;
	fill(dp[idx], dp[idx]+N, -1);
	dp[idx][0] = 0;
	REP(i, N, 0) {
		int _idx = idx;
		idx = (idx+1)%2;
		fill(dp[idx], dp[idx]+N, -1);
//		cin >> X >> Y;
		X = 200;
		Y = 100;
		REP(j, M + 1, 0) {
			if (dp[_idx][j] > -1) {
				if (j < M) {
					dp[idx][j] = max(dp[idx][j], dp[_idx][j] + Y);
					dp[idx][j+1] = max(dp[idx][j+1], dp[_idx][j] + X);
				} else {
					dp[idx][j] = max(dp[idx][j], dp[_idx][j]);
				}
			}
		}
	}
	cout << dp[idx][min(N, M)] << endl;

	return 0;
}
*/