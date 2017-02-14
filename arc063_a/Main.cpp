#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	char c = S[0];
	int res = 0;
	for (int i = 1; i < S.length(); i++) {
		if (c != S[i]) {
			res++;
			c = S[i];
		}
	}
	cout << res << endl;
}