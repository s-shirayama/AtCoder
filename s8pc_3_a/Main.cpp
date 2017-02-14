// /usr/local/bin/g++ Main.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	ll res = 0;
	for (int
	 i = 2; i <= 12; i++) {
		for (int j = 2; j <= 6; j++) {
			if (((7*i+j-7)*9)%11 == K) res++;
		}
	}
	res = res*((N-2)/11);
	for (ll i = 2; i <= (N-2)%11+1; i++) {
		for (int j = 2; j <= 6; j++) {
			if (((7*i+j-7)*9)%11 == K) res++;
		}
	}
	cout << res << endl;
}