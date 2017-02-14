#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
	int A, B, K, L;
	cin >> A >> B >> K >> L;
	LL b = K / L;
	LL a = K - b * L;
	cout << min(b * B + a * A, (b + 1) * B) << endl;
	return 0;
}