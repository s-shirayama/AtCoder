#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

string T;

int calc(int s, int e) {
	bool loop = false;
	int _res = 0;
	int res = 0;
	for (int i = s; i <= e; i++) {
		if (T[i] == '?' || (T[i] == '2' && !loop) || (T[i] == '5' && loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = true;
	_res = -2;
	for (int i = s; i <= e; i++) {
		if (T[i] == '?' || (T[i] == '2' && !loop) || (T[i] == '5' && loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = false;
	_res = 0;
	for (int i = e; i > s-1; i--) {
		if (T[i] == '?' || (T[i] == '2' && loop) || (T[i] == '5' && !loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = true;
	_res = -2;
	for (int i = e; i > s-1; i--) {
		if (T[i] == '?' || (T[i] == '2' && loop) || (T[i] == '5' && !loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	int idx = -1;
	int res = 0;
	REP(i, T.length(), 0) {
		if (T[i] != '?' && T[i] != '2' && T[i] != '5') {
			if (idx > 0) res += calc(idx, i - 1);
			idx = -1;
		} else {
			if (idx == -1) idx = i;
		}
	}
	if (idx > -1) res += calc(idx, T.length() - 1);

	cout << res << endl;
	return 0;
}
/*
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	bool loop = false;
	int _res = 0;
	int res = 0;
	for (int i = 0; i < T.length(); i++) {
		if (T[i] == '?' || (T[i] == '2' && !loop) || (T[i] == '5' && loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = true;
	_res = -2;
	for (int i = 0; i < T.length(); i++) {
		if (T[i] == '?' || (T[i] == '2' && !loop) || (T[i] == '5' && loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = false;
	_res = 0;
	for (int i = T.length()-1; i > -1; i--) {
		if (T[i] == '?' || (T[i] == '2' && loop) || (T[i] == '5' && !loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	loop = true;
	_res = -2;
	for (int i = T.length()-1; i > -1; i--) {
		if (T[i] == '?' || (T[i] == '2' && loop) || (T[i] == '5' && !loop)) {
			if (loop) _res += 2;
			if (res < _res) res = _res;
			loop = !loop;
		} else {
			_res = 0;
			loop = false;
		}
	}
	cout << res << endl;

	return 0;
}
*/
