#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
using namespace std;
typedef long long int LL;

int X, Y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y;
	if (X < Y) cout << "Better" << endl;
	else cout << "Worse" << endl;

	return 0;
}