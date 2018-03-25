#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef long double LD;
typedef pair<int, int> P;
typedef struct TrieNode {
  TrieNode *c[26];
  int cnt;
  bool isLeaf;
} TN;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;
const int INF = 1 << 30;

TN *getNode() {
  TN *d;
  d = (TN *)malloc(sizeof(TN));
  for (int i = 0; i < 26; i++) d->c[i] = NULL;
  d->cnt = 0;
  d->isLeaf = false;
  return d;
}

void insert(TN *root, string s) {
  TN *p = root;
  p->cnt++;
  for (int i = 0; i < s.length(); i++) {
    int idx = s[i] - 'a';
    if (!p->c[idx]) p->c[idx] = getNode();
    p = p->c[idx];
    p->cnt++;
  }
  p->isLeaf = true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K, A[MAXN], _A;
  string S[MAXN], _S[MAXN];

  cin >> N >> K;
  if (N == K) {
    cout << endl;
    return 0;
  }
  for (int i = 0; i < K; i++) {
    cin >> _A;
    A[i] = --_A;
  }
  for (int i = 0; i < N; i++) cin >> S[i];

  sort(A, A+K);
  TN *d = getNode();
  for (int i = 0, idx = 0; i < N; i++) {
    if (i == A[idx]) _S[idx++] = S[i];
    else insert(d, S[i]);
  }
  sort(_S, _S+K);
  int cm = 0, cm2 = 0;
  for (; cm < _S[0].length() && cm < _S[K-1].length() && _S[0][cm] == _S[K-1][cm]; cm++) ;

  for (; cm2 < cm; cm2++) {
    int idx = _S[0][cm2] - 'a';
    if (d->c[idx] == NULL) break;
    d = d->c[idx];
  }
  if (cm == cm2) {
    cout << -1;
  } else {
    for (int i = 0; i < cm2 + 1; i++) {
      cout << _S[0][i];
    }
  }
  cout << endl;
  return 0;
}