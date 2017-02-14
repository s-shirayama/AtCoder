#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	vector<int> L;
	int m = 'z' - 'a' + 1, l = S.length();
	for (int i = 0; i < l; i++) m = min(m, S[i] - 'a');
	for (int i = 0; i < l; i++) if (S[i] - 'a' == m) L.push_back(i);
	L.push_back(l);
	bool res = (S[0] - 'a' == m);
	while (L.size() > 2 && res) {
		for (int j = L.size() - 3; j >= 0; j--) {
			res = true;
			for (int i = 0; i < L[j+1] - L[j] && res; i++) {
				if (L[j+1] + i == L[j+2] || S[L[j]+i] > S[L[j+1]+i]) res = false;
				else if (S[L[j]+i] < S[L[j+1]+i]) break;
			}
			if (res) {
				L.erase(L.begin() + 1 + j);
				break;
			}
		}
	}
	cout << (res?"Yes":"No") << endl;
	return 0;
}