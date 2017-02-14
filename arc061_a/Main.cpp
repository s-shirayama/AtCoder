#include<iostream>
using namespace std;

long long calculate(long long base, long long num[], long long size) {
	long long sum = 0;
	long long cur = 0;
	for (long long i = 0; i < size; i++) {
		cur = cur * 10 + *(num++);
		sum += calculate(base+cur, num, size - i - 1);
	}
	if (sum == 0) {
		sum = base;
	}
	return sum;
}

int main() {
	string S;
	cin >> S;
	long long num[S.length()];
	for (long long i = 0; i < S.length(); i++) {
		num[i] = (int)(S.at(i) - '0');
	}
	cout << calculate(0, num, S.length()) << "\n";
}

