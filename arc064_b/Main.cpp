#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	cout << (((S[0] == S[S.length()-1]) ^ (S.length()%2 == 1)) ? "First" : "Second") << endl;
	return 0;
}