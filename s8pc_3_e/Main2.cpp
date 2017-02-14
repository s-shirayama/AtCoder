#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long int LL;

int N;
LL K;
double s[200001];

int count(int i, double X) {
	int all = (N - i) / 2;
	int l = 0, r = all + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		double area = (s[i] + s[m] + s[N - i - m]) / 2.0;
		if (area > X) r = m;
		else l = m;
	}
	if (r == all + 1) return N - i - 1;
	return l * 2;
}

bool check(double X) {
	LL sum = 0.0;
	REP(i, N - 1, 1) {
		sum += count(i, X);
	}
	return sum * N >= 3 * K;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	REP(i, N, 1) {
		s[i] = sin(2.0*PI*(double)i/(double)N);
	}
	double l = 0.0, r = PI;
	REP(i, 50, 0) {
		double m = (l + r) / 2.0;
		if (check(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(10) << r << endl;
}
