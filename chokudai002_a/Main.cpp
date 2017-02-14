#include<iostream>
using namespace std;
int main() {
	long long idx = 2;
	long long num;
	int cnt = 0;
	int result = 1;
	while (cnt < 100) {
		num = 1;
		while (true) {
			if (num%idx != 0) {
				if (num * idx < 1000000000) {
					num *= idx;
					result++;
				} else {
					cout << num << "\n";
					cnt++;
					break;
				}
			}
			idx++;
		}
	}
	//cout << "result: " << result;
}