#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 100001
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

int N, A, B;
LL D, X[SIZE], Y[SIZE];
set<int> chk[SIZE];

LL calc(int n1, int n2) {
	LL res = 0;
	if (X[n1] > X[n2]) res += X[n1] - X[n2];
	else res += X[n2] - X[n1];
	if (Y[n1] > Y[n2]) res += Y[n1] - Y[n2];
	else res += Y[n2] - Y[n1];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> A >> B;
	REP(i, N, 0) cin >> X[i+1] >> Y[i+1];

/*
	N = 20000;
	A = 1;
	B = 2;
	REP(i, N, 0) {
		X[i+1] = i/1000 + 1;
		Y[i+1] = i%1000 + 1;
	}
cout << "hoge" << endl;
*/
	int a = A, b = B;
	D = calc(A, B);
	queue<P> q;
	set<int> s;
	s.insert(A);
	s.insert(B);
	q.push(P(A,B));
	q.push(P(B,A));
	chk[A].insert(B);
	chk[B].insert(A);
	int res = 1;
	while (q.size()) {
		P p = q.front();
		q.pop();
		REP(i, N+1, 1) {
			if (calc(i, p.first) == D && p.second != i && chk[p.first].count(i) == 0) {
				res++;
				chk[i].insert(p.first);
				if (s.count(i) == 0) {
					s.insert(i);
					q.push(P(i,p.first));
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
