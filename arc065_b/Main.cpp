#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 200001
using namespace std;
typedef long long int LL;
typedef long double LD;

struct UF {
	int par[SIZE], ran[SIZE];
	void init(int n) {
		REP(i, n, 0) par[i] = i;
	}
	int getpar(int n) {
		if (par[n] == n) return n;
		par[n] = getpar(par[n]);
		return par[n];
	}
	void mrg(int a, int b) {
		a = getpar(a), b = getpar(b);
		if (a == b) return;
		if (ran[a] > ran[b]) par[a] = b;
		else {
			par[b] = a;
			if (ran[a] == ran[b]) ran[a]++;
		}

	}
} UA, UB;

vector<int> hv[SIZE];
int freq[SIZE];
int ans[SIZE];
int N, K, L, A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> L;
	UA.init(N);
	UB.init(N);
	while (K--) {
		cin >> A >> B;
		UA.mrg(--A, --B);
	}
	while (L--) {
		cin >> A >> B;
		UB.mrg(--A, --B);
	}
	REP(i, N, 0) hv[UA.getpar(i)].push_back(i);
	REP(i, N, 0) if (hv[i].size()) {
		for (int u: hv[i]) freq[UB.getpar(u)]++;
		for (int u: hv[i]) ans[u] = freq[UB.getpar(u)];
		for (int u: hv[i]) freq[UB.getpar(u)]--;
	}
	REP(i, N, 0) cout << ans[i] << " ";
	cout << endl;
	return 0;
}

/*
int N, K, L;
// CT : Route, _CT : Group Stations
set<int> CT[2][SIZE], _CT[2][SIZE];
// ct : Group No
int ct[2][SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> L;
	int p, q, r, s, res[SIZE];
	memset(res, 0, sizeof(res));
	memset(ct, 0, sizeof(ct));

	while (K--) {
		cin >> p >> q;
		CT[0][p].insert(q);
		CT[0][q].insert(p);
	}
	while (L--) {
		cin >> r >> s;
		CT[1][r].insert(s);
		CT[1][s].insert(r);
	}

	REP(i, N+1, 1) {
		queue<int> que;
		set<int> cpy;
		// Find Routes
		REP(j, 2, 0) {
			if (ct[j][i] > 0) continue;
			ct[j][i] = i;
			que.push(i);
			_CT[j][i].insert(i);
			if (j == 1) res[i]++;
			while (que.size()) {
				int a = que.front();
				que.pop();
				for (int c : CT[j][a]) {
					if (_CT[j][i].count(c) > 0) continue;
					if (j == 1 && _CT[0][ct[0][i]].count(c)) {
						cpy.insert(c);
						res[i]++;
					}
					ct[j][c] = i;
					_CT[j][i].insert(c);
					que.push(c);
				}
			}
		}
		// Calculate result
		if (res[i] == 0) {
			for (int c : _CT[0][ct[0][i]]) {
				if (_CT[1][ct[1][i]].count(c) > 0) {
					cpy.insert(c);
					res[i]++;
				}
			}
		}
		// Copy result to other index
		for (int c : cpy) {
			res[c] = res[i];
		}
	}
	REP(i, N, 1) cout << res[i] << " ";
	cout << res[N] << endl;

	return 0;
}

*/