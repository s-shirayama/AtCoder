#include <bits/stdc++.h>
#define REP(i, n, s) for (LL i = (s); i < (n); i++)
#define SIZE 100001
using namespace std;
typedef long long int LL;
typedef long double LD;

int N, A[SIZE];
bool B[SIZE];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	queue<int> que[5];
	REP(i, N, 0) {
		cin >> A[i];
		que[A[i]].push(i);
	}
	int res = 0;
	REP(i, N, 0) {
		if (!B[i]) {
			res++;
			B[i] = true;
			que[A[i]].pop();
			int d = 4 - A[i];
			for(int j = d; j > 0; j--) {
				if(que[j].size()) {
					int s = que[j].front();
					que[j].pop();
					B[s] = true;
					d -= j;
					j = d + 1;
				}
			}
		}
	}
	cout << res << endl;

	return 0;
}
