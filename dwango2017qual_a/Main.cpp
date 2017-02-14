#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

int N, A, B;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> A >> B;

	cout << max(A + B - N, 0) << endl;
	return 0;
}
