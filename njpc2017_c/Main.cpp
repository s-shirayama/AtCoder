#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int MAXN = 1e5+1;
const double EPS = 1e-6;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	LL N, L, X[MAXN];
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
//		scanf("%d", X+i);
		cin >> X[i];
	}
	X[N] = X[N-1] + 2*L + 1;

	LL l = 0;
	LL r = X[0];
	bool res = true;
	for (int i = 0; i < N; i++) {
		if (X[i] - r >= L) {
			res = false;
			break;				
		}
		if (X[i+1] - X[i] >= L) {
			if (l < X[i] - L) l = X[i] + L;
			else l += 2 * L;
			if (l >= X[i+1]) {
				res = false;
				break;
			}
			r = X[i+1];
		}
	}
	cout << (res?"YES":"NO") << endl;
	return 0;
}