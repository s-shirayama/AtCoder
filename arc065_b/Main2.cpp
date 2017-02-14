#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 200001
using namespace std;

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
	void mgr(int a, int b) {
		a = getpar(a), b = getpar(b);
		if (a == b) return;
		if (ran[a] > ran[b]) par[b] = a;
		else {
			par[a] = b;
			if (ran[a] == ran[b]) ran[b]++;
		}
	}
} UA, UB;

vector<int> hv[SIZE];
int N, K, L, A, B;
int freq[SIZE], ans[SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> L;
	UA.init(N);
	UB.init(N);
	while (K--) {
		cin >> A >> B;
		UA.mgr(--A, --B);
	}
	while (L--) {
		cin >> A >> B;
		UB.mgr(--A, --B);
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