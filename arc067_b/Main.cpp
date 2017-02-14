#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int N;
	LL A, B, X;
	cin >> N >> A >> B >> X;
	LL pre = X, ans = 0;
	for (int i = 1; i < N; i++) {
		cin >> X;
		ans += min((X - pre) * A, B);
		pre = X;
	}
	cout << ans << endl;
	return 0;

}