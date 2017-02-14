#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

string S;
set<string> T;

void initialize() {
	T.clear();
	T.insert("dream");
	T.insert("dreamer");
	T.insert("erase");
	T.insert("eraser");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	int idx = 0;
	initialize();
	for (int i = S.length() - 1; i >= 0; i--) {
		bool reset = false;
		for (string s : T) {
			if (s[s.length() - idx - 1] == S[i]) {
				if (s.length() - 1 == idx) {
					idx = 0;
					initialize();
					reset = true;
					break;
				}
			} else {
				T.erase(s);
			}
		}
		if (reset) continue;
		if (T.size() == 0) {
			cout << "NO" << endl;
			return 0;
		}
		idx++;
	}
	cout << "YES" << endl;
	return 0;
}

/*
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	regex r("(dream|dreamer|erase|eraser)+$");
	smatch match;
	if (regex_match(S, match, r)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
*/