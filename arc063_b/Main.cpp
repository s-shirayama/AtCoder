#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = s; i < n; i++)
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, T, A[100000];
	cin >> N >> T;
	REP(i, N, 0) cin >> A[i];
	int tmp1 = 0, tmp2 = -1, res = 0;
	REP(i, N, 1) {
		tmp1 = max(tmp1, A[N-i]);
		if (tmp1 - A[N-i-1] == tmp2) {
			res++;
		} else if (tmp1 - A[N-i-1] > tmp2) {
			res = 1;
			tmp2 = tmp1 - A[N-i-1];
		}
	}
	cout << res << endl;
	return 0;
}