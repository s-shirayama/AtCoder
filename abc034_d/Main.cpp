#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1000
using namespace std;
typedef long long int LL;
typedef long double LD;

int N, K;
LL W[SIZE];
double P[SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	REP(i, N, 0) cin >> W[i] >> P[i];
	double lb = 0.0, ub = 100.0, mid;
	REP(i, 114, 0) {
		mid = (lb + ub) / 2.0;
		priority_queue<double> q;
		REP(j, N, 0) q.push(W[j] * (P[j] - mid));
		double sum = 0.0;
		REP(j, K, 0) {
			sum += q.top();
			q.pop();
		}
		if (sum >= 0.0) lb = mid;
		else ub = mid;
	}
	cout << fixed << setprecision(9) << mid << endl;
}

/*
int K, N, P, c[1000];
LL W[1000];
LD S[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(c, 0, sizeof(c));
	cin >> N >> K;
	REP(i, N, 0) {
		cin >> W[i] >> P;
		S[i] = W[i] * (double)P / 100.0;
	}

	LL w = 0;
	LD s = 0.0;
	while (K--) {
		LL maxw = 1;
		LD maxs = 0.0;
		int idx = 0;
		REP(i, N, 0) {
			if (c[i]) continue;
			if ((s + S[i]) / (w + W[i]) > maxs / maxw) {
				idx = i;
				maxw = w + W[i];
				maxs = s + S[i];
			}
		}
		c[idx] = 1;
		w = maxw;
		s = maxs;
	}

	cout << fixed << setprecision(9) << s/w*100.0 << endl;
	return 0;
}
*/