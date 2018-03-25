#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1 << 30;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  LL N, M, res;
  cin >> N >> M;
  if (N * 2 > M) {
    res = M / 2;
  } else {
    res = N;
    M -= N * 2;
    res += M / 4;
  }
  cout << res << endl;
  return 0;
}