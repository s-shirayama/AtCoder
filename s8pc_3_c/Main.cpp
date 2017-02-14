// /usr/local/bin/g++ Main.cpp -std=c++14
#include <bits/stdc++.h>
#define REP(i,n,s) for (int i = (s); i < (n); i++)
#define MOD 1000000007;
using namespace std;
typedef long long int LL;

int N, K;
LL p[101], l[256][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	cin >> N >> K;
	p[0] = 1;
	REP(i, N+1, 1) {
		p[i] = p[i-1]*i%MOD;
	}

	int a;
	LL tmp[256][101];
	REP(i, N, 0) {
		cin >> a;
		memset(tmp,0,sizeof(tmp));
		
		REP(j, 256, 0) {
			REP(k, 101, 0) {
				tmp[j][k] = (tmp[j][k]+l[j][k])%MOD;
				tmp[j^a][k+1] = (tmp[j^a][k+1]+l[j][k])%MOD;
			}
		}
		tmp[a][1]++;
		memcpy(l, tmp, sizeof(l));
	}
	LL res = 0;
	REP(i, 101, 1) {
		res = (res+p[i]*l[K][i])%MOD;
	}
	cout << res << endl;
}

/*
ll calc(int x, int cnt, int a[]) {
	if (*a == 0) {
		return (x == K && cnt > 0) ? p[cnt] : 0;
	}
	return (calc(x, cnt, a+1)+calc((x^(*a)), cnt+1, a+1))%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	cin >> N >> K;
	p[0] = 1;
	for (int i = 0; i < 101; i++) {
		if (i > 0 && i <= N) {
			p[i] = p[i-1]*i%MOD;
		}
		if (i < N) {
			cin >> A[i];
		} else {
			A[i] = 0;
		}
	}
	cout << calc(0, 0, A) << endl;
}
*/