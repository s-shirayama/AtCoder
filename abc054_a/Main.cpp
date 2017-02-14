#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1 << 30;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	if (B != 1 && (A == 1 || A > B)) {
		cout << "Alice" << endl;
	} else if (A != 1 && (B == 1 || B > A)) {
		cout << "Bob" << endl;
	} else {
		cout << "Draw" << endl;
	}
	return 0;
}