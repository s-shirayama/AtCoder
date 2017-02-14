#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int L;
	string S;
	cin >> L >> S;
	for (int i = 0; i < L && i <  S.length(); i++) {
		cout << S[i];
	}
	cout << endl;

	return 0;
}