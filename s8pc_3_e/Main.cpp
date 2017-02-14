// g++ Main.cpp -std=c++14
#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long int LL;

int N;
LL K;
double s[200001];

// Count number of triangles whose area is less than X
// Another point comes right to others.
// i : position of the point
// X : target area size
int count(int i, double X) {
	int all = (N - i) / 2;
	int l = 0, r = all + 1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		double area = (s[i] + s[m] + s[N - i - m]) / 2.0;
		if (area > X) r = m;
		else l = m;
	}
	if (r == all + 1) return N - i - 1;
	return l * 2;
}

bool check(double X) {
	LL sum = 0;
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
	double l = 0.0, r = 2.0 * PI;
	// (1/2)^50 = 8.881784197001252e-16
	REP(i, 50, 0) {
		double m = (l + r) / 2;
		if (check(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(20) << r << endl;
	return 0;
}


/*
LD coef, cache[200000];

bool sortGenerator(const pair<LD, int>& left, const pair<LD, int>& right) {
	return left.first < right.first;
}

LD calc(int l1, int l2, int l3) {
	if (cache[l1] == 0) cache[l1] = sin(l1*coef);
	if (cache[l2] == 0) cache[l2] = sin(l2*coef);
	if (cache[l3] == 0) cache[l3] = sin(l3*coef);
	return (cache[l1] + cache[l2] + cache[l3])/2.0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	memset(cache, 0.0, sizeof(cache));
	vector<pair<LD, int> > pv;
	cin >> N >> K;
	coef = PI/N*2;
	REP(i, N/3 + 1, 1) {
		REP(j, (N - i)/2 + 1, i) {
			int k = N - i - j;
//calc(i,j,k);
			pv.push_back(pair<LD, int>(calc(i, j, k), (i == j && j == k)?N/3:N));
		}
	}
	
	sort(pv.begin(), pv.end(), sortGenerator);
	LD res = 0.0;
	int k = K;
	for (pair<LD, int> p : pv) {
		res = p.first;
		k -= p.second;
		if (k <= 0) break;
	}
	cout << fixed << setprecision(20) << res << endl;
}
*/
