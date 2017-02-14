#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, A[MAXN];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A+N);
	int pre = A[0], cnt = 0;
	for (int i = 1; i < N; i++) {
		if (pre == A[i]) cnt++;
		else pre = A[i];
	}
	cout << N-cnt-((cnt%2==1)?1:0) << endl;
	return 0;
}