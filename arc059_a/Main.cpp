// 12:03:12 -> 12:12:53 = 9:40
#include <bits/stdc++.h>
#define REP(i, n, s) for (int i = (s); i < (n); i++)
#define SIZE 1
using namespace std;
typedef long long int LL;
typedef long double LD;

int main() {
	int N, A[100];
	scanf("%d", &N);
	int sum = 0;
	REP(i, N, 0) {
		scanf("%d", A+i);
		sum += A[i];
	}
	int avg = round((double)sum/N);
	int cost = 0;
	REP(i, N, 0) {
		cost += (avg - A[i]) * (avg - A[i]);
	}
	printf("%d\n", cost);

	return 0;
}

