#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAXN = 2002;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const char c[4] = {'L', 'U', 'R', 'D'};

bool m[MAXN][MAXN];

void _reset(int sx, int sy, string s) {
	memset(m, 0, sizeof(m));
	int x = sx, y = sy;
	for (int i = 0; i < s.length(); i++) {
		m[x][y] = true;
		for (int j = 0; j < 4; j++) {
			if (s[i] == c[j]) {
				x += dx[j];
				y += dy[j];
			}
		}
	}
}

int main() {
	int SX, SY, TX, TY;
	cin >> SX >> SY >> TX >> TY;
	SX += 1001;
	SY += 1001;
	TX += 1001;
	TY += 1001;

	memset(m, 0, sizeof(m));
	queue<pair<P, string>> q;
	q.push(make_pair(make_pair(SX, SY), ""));
	P g[4] = {P{TX, TY}, P{SX, SY}, P{TX, TY}, P{SX, SY}};
	int idx = 0;
	string s;
	while (q.size()) {
		pair<P, string> v = q.front(); q.pop();
		P p = v.first;
		s = v.second;
		if (p.first == g[idx].first && p.second == g[idx].second) {
			queue<pair<P, string>>().swap(q);
			if (++idx >= 4) break;
			_reset(SX, SY, s);
			m[g[idx].first][g[idx].second] = false;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.first + dx[i], y = p.second + dy[i];
			if (x < 0 || x >= MAXN || y < 0 || y >= MAXN || m[x][y]) continue;
			m[x][y] = true;
			q.push(make_pair(make_pair(x, y), s + c[i]));
		}
	}
	cout << s << endl;
	return 0;
}