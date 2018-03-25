#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;
const int INF = 1 << 30;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  LL A[MAXN];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A+N);
  LL sum = 0;
  for (int i = 0; i < K; i++) {
    sum += A[i] + i;
  }
  cout << sum << endl;
  return 0;
}