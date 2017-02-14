#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	unsigned long long T[N], A[N];
	unsigned long long maxT = 0, maxA = 0;
	int idxT, idxA;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		if (T[i] > maxT) {
			idxT = i;
		}
		maxT = max(maxT, T[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		maxA = A[0];
		if (A[i] == maxA) {
			idxA = i;
		}
	}
	if (maxA != maxT || idxT > idxA) {
		cout << 0;
		return 0;
	}
	unsigned long long result = 1;
	unsigned long long pre = 0;
	int idx = 0;
	while (true) {
		if (pre == T[idx]) {
			result = T[idx] * result % 1000000007;
		} else {
			pre = T[idx];
		}
		if (maxT == T[idx]) {
			break;
		}
		idx++;
	}
	pre = 0;
	for (int i = N - 1; i > idx; i--) {
		if (pre == A[i]) {
			result = A[i] * result % 1000000007;
		} else {
			pre = A[i];
		}
	}
	cout << result;
	return 0;
}
