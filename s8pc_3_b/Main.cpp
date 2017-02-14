// /usr/local/bin/g++ Main.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W, K, C[30*30];

ll calc(int idx) {
	int _c[30*30];
	set<int> d; // deleted blocks
	for (int k = 0; k < 30*30; k++) {
		_c[k] = C[k];
	}
	d.insert(idx);
	int cnt = 0;
	ll res = 0;

	// Continue until there is no deleted block.
	while (d.size()) {
		// Move blocks.
		for (int l : d) {
			int _h = l/W;
			int _w = l%W;
			for (int i = _h; i > 0; i--) {
				_c[i*W+_w] = _c[(i-1)*W+_w];
			}
			_c[_w] = 0;
		}
		d.clear();

		// Find deletable blocks.
		for (int i = 1; i < H; i++) {
			for (int j = 0; j < W - K + 1; j++) {
				bool judge = true;
				for (int k = 1; k < K; k++) {
					judge = (judge && _c[i*W+j] != 0 && _c[i*W+j] == _c[i*W+j+k]);
				}
				if (!judge) continue;
				for (int k = 0; k < K; k++) {
					d.insert(i*W+j+k);
				}
			}
		}

		// Add score
		if (d.size()) {
			int _res = 0;
			for (int l : d) {
				_res += _c[l];
			}
			for (int i = 0; i < cnt; i++) {
				_res *= 2;
			}
			res += _res;
		}
		cnt++;
	}

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Dummy input
//	ifstream in("input.txt");
//	cin.rdbuf(in.rdbuf());

	// Read input
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		int j = 0;
		for (char& c : s) {
			C[i*W+(j++)] = (int)(c - '0');
		}
	}

	ll res = 0;
	for (int i = 1; i < H; i++) {
		for (int j = 0; j < W; j++) {
			ll _res = calc(i*W+j);
			if (res < _res) res = _res;
		}
	}
	cout << res << endl;
}
