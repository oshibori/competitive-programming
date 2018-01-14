#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T, Q;
  cin >> N >> T >> Q;
  vector<int> A(N), D(N);
  rep(i, 0, N) { cin >> A[i] >> D[i]; }
  vector<int> X(Q);
  rep(i, 0, Q) {
    cin >> X[i];
    X[i]--;
  }

  vector<int> p(N);
  int x = 0;
  while (x < N and D[x] == 2) {
    p[x] = A[x]-T;
    x++;
  }
  while (0 < N and D[N - 1] == 1) {
    p[N - 1] = A[N-1]+T;
    N--;
  }
  while (x < N) {
    int a = x;
    while (x < N and D[x] == 1) {
      x++;
    }
    int b = x;
    while (x < N and D[x] == 2) {
      x++;
    }
    int c = x;

    int m = (A[b - 1] + A[b]) / 2;

    rep(i, a, b) p[i] = min(m, A[i] + T);
    rep(i, b, c) p[i] = max(m, A[i] - T);
  }

  while (x < N and D[x] == 1) {
    p[x] = INF;
    x++;
  }

  rep(i, 0, Q) cout << p[X[i]] << endl;
  return 0;
}
