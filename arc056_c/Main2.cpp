#include <bits/stdc++.h>
using namespace std;

int sum[1<<18], d[1<<19];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A[17][17];
	int N, M;
	cin >> N >> M;
	// Input
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];

	// Calc sum[]
	for (int i = 0; i < 1<<N; i++) for (int j = 0; j < N; j++)
		for (int k = j + 1; k < N; k++) if ((i>>j)&1 && (i>>k)&1) sum[i] += A[j][k];

	// Main
	for (int i = 0; i < 1<<N; i++) {
		d[i] = M;
		// Loop of subset of i
		for (int j = (i-1)&i; j > 0; j = (j-1)&i) {
			d[i] = max(d[i], d[j] + M - sum[i] + sum[j] + sum[i-j]);
		}
	}

	// Print result
	cout << d[(1<<N)-1] << endl;

	return 0;
}