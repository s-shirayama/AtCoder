#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;

int N, Q, A;
LL B, res[100001];

LL count(int m, int a) {
	LL sum = 0;
	REP(i, a-m, 0) {
		sum += (res[a-i-1] - res[a-i]) * (i + 1);
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	memset(res, 0, sizeof(res));
	res[0] = 20000000000000;
	cin >> N >> Q;
//	N = 100000, Q = 100000;
	while (Q--) {
		cin >> A >> B;
//		A = N, B = 1;
		if (B == 1) {
			int l = 0, r = A;
			while (r - l > 1) {
				int m = (r + l) / 2;
				if (res[m] != res[A]) l = m;
				else r = m;
			}
			res[r]++;
			continue;
		}
		int l = 0, r = A;
		while (r - l > 1) {
			int m = (r + l) / 2;
//			cout << m << ":" << A << ":" << count(m, A) << endl;
			if (count(m, A) > B) l = m;
			else r = m;
		}
		LL p = res[r];
		REP(i, A + 1, r + 1) {
			if (res[i] != p) {
				REP(j, A + 1, i) {
					B -= (p - res[j]);
					res[j] = p;
				}
				break;
			} else {
				p = res[i];
			}
		}
//		cout << r << endl;
		REP(i, A + 1, r) {
			res[i] += B/(A - r + 1);
		}
		REP(i, r + B%(A - r + 1), r) {
			res[i]++;
		}
//		REP(i, N + 1, 1) cout << res[i];
//		cout << endl;
	}
	REP(i, N + 1, 1) cout << res[i] << endl;
}

/*
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	memset(res, 0, sizeof(res));
	res[0] = 20000000000000;
	cin >> N >> Q;
//	N = 10000, Q = 100000;
	while (Q--) {
		cin >> A >> B;
//		A = N, B = 1;
		LL v = res[A];
		int idx = A;
		REP(i, A, 0) {
			LL d = res[A-i-1] - res[A-i];
			int i1 = i+1;
			if (d > 0) {
				idx = A - i;
				if ((LL)(d*i1) <= B) {
					v += d;
					B -= (LL)(d*i1);
				} else {
					v += (LL)(B/i1);
					B-= (LL)(B/i1) * i1;
					break;
				}
			}
		}
		REP(i, A + 1, idx) {
			res[i] = v;
		}
		REP(i, idx + B, idx) {
			res[i]++;
		}
	}
	REP(i, N + 1, 1) cout << res[i] << endl;
}
*/

/*
int N, Q, A;
LL B, res[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(res, 0, sizeof(res));
	cin >> N >> Q;
	while (Q--) {
		cin >> A >> B;
		REP(i, B, 0) {
			int idx = 0;
			LL v = res[0];
			REP(j, A, 1) {
				if (res[j] < v) {
					idx = j;
					v = res[j];
				}
			}
			res[idx]++;
		}
	}
	REP(i, N, 0) {
		cout << res[i] << endl;
	}
	return 0;
}
*/