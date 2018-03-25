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

  string S, _S = "yahoo";
  cin >> S;
  sort(_S.begin(), _S.end());
  sort(S.begin(), S.end());
  cout << ((S == _S)?"YES":"NO") << endl;
  return 0;
}