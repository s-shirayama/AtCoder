#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int> > mass;

ll H, W, zero = 0, ans[10];
int N, A, B;

int main() {
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		for (int j = A - 1; j <= A + 1; j++) {
			for (int k = B - 1; k <= B + 1; k++) {
				pair<int, int> p(j, k);
				mass.push_back(p);
			}
		}
	}
	sort(mass.begin(), mass.end());
	for (int i = 0; i < mass.size(); i++) {
		if (mass[i].first > 1 && mass[i].first < H && mass[i].second > 1 && mass[i].second < W) {
			int j = 0;
			pair<int, int> p(mass[i]);
			zero++;
			while (true) {
				if (p == mass[i]) {
					j++;
					i++;
				} else {
					ans[j]++;
					i--;
					break;
				}
			}
		}
	}
	ans[0] = (H - 2) * (W - 2) - zero;
	for (int i = 0; i < 10; i++) {
		cout << ans[i] << endl;
	}
}