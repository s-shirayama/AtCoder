#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
	LL A, K;
	cin >> A >> K;
	LL cnt = 0;
	if (K == 0) {
		cout << fixed << setprecision(0) << (2*1e12 - A) << endl;
		return 0;
	}
	while(A < 2*1e12) {
		A += 1 + K * A;
		cnt++;
	}
	cout << fixed << cnt << endl;
	return 0;
}
