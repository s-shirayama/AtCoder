#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	LL A[MAXN], B[MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	LL cnt = 0;
	for (int i = N-1; i >= 0;) {
//		if ((A[i]+cnt) == 0 || (A[i]+cnt)%B[i] > 0) {
		if ((A[i]+cnt)%B[i] > 0) {
			cnt += B[i] - ((A[i]+cnt)%B[i]);
		} else {
			i--;
		}
	}
	cout << cnt << endl;

	return 0;
}

	