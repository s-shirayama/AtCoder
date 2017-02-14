// 12:15 -> 12:31 = 16min
#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

int main() {
	string S;
	cin >> S;
	if (S[0] == S[1]) {
		cout << "1 2" << endl;
		return 0;
	}
	char pre1 = S[1], pre2 = S[0];
	REP(i, S.length(), 2) {
		if (S[i] == pre1) {
			cout << i << " " << i + 1 << endl;
			return 0;
		} else if (S[i] == pre2) {
			cout << i - 1 << " " << i + 1 << endl;
			return 0;
		}
		pre1 = S[i];
		pre2 = S[i-1];
	}
	cout << "-1 -1" << endl;
	return 0;
}




