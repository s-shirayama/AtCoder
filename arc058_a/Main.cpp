// 18:36 -> 19:35 = 59min
#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

set<int> D;

int _max(int n) {
	int res = -1;
	REP(i, 10, n) {
		if (D.count(i) == 0) {
			res = i;
			break;
		}
	}
	return res;
}

int main() {
	int N, K, d, logV;
	vector<int> v;
	scanf("%d %d", &N, &K);
	REP(i, K, 0) {
		scanf("%d", &d);
		D.insert(d);
	}
	for (logV = 1; logV <= N; logV *= 10) {
		v.push_back((N%(logV*10))/logV);
	}
	reverse(v.begin(), v.end());

	vector<int> r;
	r.push_back(0);
	bool chk = false;
	REP(i, v.size(), 0) {
		int res = _max((chk)? 0 : v[i]);
		if (res != v[i]) chk = true;
		if (res == -1) {
			chk = true;
			int _i = i;
			while(1) {
				r[_i]++;
				if (_max(r[_i]) == -1) {
					r[_i] = _max(0);
					_i--;
				} else {
					r[_i] = _max(r[_i]);
					break;
				}
			}
			r.push_back(_max(0));
		} else {
			r.push_back(res);
		}
	}

	if (r[0] > 0) cout << r[0];
	for (int i = 1; i < r.size(); i++) cout << r[i];
	cout << endl;

	return 0;
}
