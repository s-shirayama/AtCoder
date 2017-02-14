#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X, A, pre = 0;
	cin >> N >> X;
	LL res = 0;
	while (N--) {
		cin >> A;
		if (A + pre > X) {
			res += A + pre - X;
			A -= A + pre - X;
		}
		pre = A;
	}

	cout << res << endl;
	return 0;
}