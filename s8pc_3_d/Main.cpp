// /usr/local/bin/g++ Main.cpp -std=c++14
#include <bits/stdc++.h>
#define REP(i,n,s) for (int i = (s); i < (n); i++)
#define SIZE 201
using namespace std;
typedef long long int LL;

int H, W, A[SIZE][SIZE], dp[2][SIZE][SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
	ifstream in("input.txt");
	cin.rdbuf(in.rdbuf());

	memset(A, 0, sizeof(A));
	cin >> H >> W;
	REP(i, H, 0) {
		REP(j, W, 0) {
			cin >> A[i][j];
		}
	}

	int pos = 0;
	memset(dp, -1, sizeof(dp));
	dp[pos][0][0] = A[0][0];
	REP(i, H+W-1, 1) {
		pos ^= 1;
		memset(dp[pos], -1, sizeof(dp[pos]));
		REP(j, W, 0) {
			REP(k, W, 0) {
				if (dp[pos^1][j][k] == -1) continue;
				REP(x, j+2, j) {
					REP(y, k+2, k) {
						int s = i - x, t = i - y;
						if (s<0||s>=H||t<0||t>=H||x>=W||y>=W) continue;
						dp[pos][x][y] = max(dp[pos][x][y], dp[pos^1][j][k] + A[s][x] + (s==t?0:A[t][y]));
					}
				}
			}
		}
	}
	cout << dp[pos][W-1][W-1] << endl;
}


/*
int H, W, A[SIZE][SIZE];
int cache[SIZE][SIZE][SIZE];

LL calc(int x1, int y1, int x2, int y2) {
	if (cache[x1][y1][x2] > -1) return cache[x1][y1][x2];
	if (x1 == H || y1 == W || x2 == H || y2 == W) {
		return 0;
	}
	if (x1 == H-1 && y1 == W-1 && x2 == H-1 && y2 == W-1) {
		return A[H-1][W-1];
	}
	LL res = 0;
	if (x1 == x2) {
		res += A[x1][y1];
		res += max(
			max(
				calc(x1+1, y1, x2+1, y2),
				calc(x1+1, y1, x2, y2+1)
			), calc (x1, y1+1, x2, y2+1));
	} else {
		res += A[x1][y1] + A[x2][y2];
		res += max(
			max(
				calc(x1+1, y1, x2+1, y2),
				calc(x1+1, y1, x2, y2+1)
			), max(
				calc(x1, y1+1, x2+1, y2),
				calc(x1, y1+1, x2, y2+1)));
	}
	cache[x1][y1][x2] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	cin >> H >> W;
	REP(i, H, 0) {
		REP(j, W, 0) {
			cin >> A[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << calc(0, 0, 0, 0) << endl;
}
*/