#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1 << 30;
const int MAXN = 50;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	bool n[MAXN][MAXN], m[MAXN][MAXN];
	string S;
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < S.length(); j++) n[i][j] = (S[j] == '#');
	}
	for (int i = 0; i < M; i++) {
		cin >> S;
		for (int j = 0; j < S.length(); j++) m[i][j] = (S[j] == '#');
	}

	bool res = false;
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			res = true;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (n[i+k][j+l] != m[k][l]) {
						res = false;
						break;
					}
				}
				if (!res) break;
			}
			if (res) break;
		}
		if (res) break;
	}

	cout << (res?"Yes":"No") << endl;
	return 0;
}