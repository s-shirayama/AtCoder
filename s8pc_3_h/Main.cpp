#include <bits/stdc++.h>
#define REP(i,n,s) for (int i = (s); i < (n); i++)
#define SIZE 50
using namespace std;
typedef long long int LL;

LL MOD;
int H, W, N, C, m[SIZE][SIZE];

int inOut(int x1, int y1, int x2, int y2) {
	int res;
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	cin >> res;
	return res;
}

int divide(int n1, int n2) {
	int r = 1;
	while (1) {
		if (r*2 >= n2 - n1 + 1) break;
		r <<= 1;
	}
	return r + n1 - 1;
}

void _f(int x1, int y1, int x2, int y2, int n) {
	if ((x2-x1+1)*(y2-y1+1) == n) {
		for(int i = x1; i < x2 + 1; i++) {
			for(int j = y1; j < y2 + 1; j++) {
				m[i][j] = 1;
			}
		}
		return;
	}
	if (x1 == x2 && y1 == y2) {
		m[x1][y1] = inOut(x1, y1, x1, y1);
		return;
	}
	if (x2 - x1 > y2 - y1) {
		int _x = divide(x1, x2);
		int r = inOut(x1, y1, _x, y2);
		if (r != 0) _f(x1, y1, _x, y2, r);
		if (r != n) _f(_x+1, y1, x2, y2, n-r);
	} else {
		int _y = divide(y1, y2);
		int r = inOut(x1, y1, x2, _y);
		if (r != 0) _f(x1, y1, x2, _y, r);
		if (r != n) _f(x1, _y+1, x2, y2, n-r);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W >> N >> MOD;

	memset(m, 0, sizeof(m));
/*
	int idx = 0;
	while (N) {
		int i = idx/W, j = idx%W;
		cout << "? " << i << " " << j << " " << i << " " << j << endl;
		cin >> m[i][j];
		if (m[i][j] > 0) {
			N--;
		}
		idx++;
	}
*/
	_f(0, 0, H-1, W-1, N);

	LL res = 0, p = 1;
	REP(i, H, 0) {
		REP(j, W, 0) {
			res = (res + p * m[i][j] % MOD) % MOD;
			p = p * 2 % MOD;
		}
	}
	cout << "! " << res << endl;
}