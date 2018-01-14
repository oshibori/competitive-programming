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
template <typename T> struct RangeAddQuery {
  int n;
  vector<T> d;
  RangeAddQuery(int m) {
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, T(0));
  }
  void add(int a, int b, T x = 0, int k = 1, int l = 0, int r = -1) {
    if (r == -1)
      r = n;

    if (r <= a || b <= l)
      return;
    else if (a <= l && r <= b) {
      // if (x >= 0)
      d[k] += (r - l) * x;
      return;
    } else {
      // d[ [l,r) ] += z が保てなくなるので、子に値を下す
      if (d[k] != 0) {
        d[2 * k] += d[k] / 2;
        d[2 * k + 1] += d[k] / 2;
        d[k] = 0;
      }
      add(a, b, x, 2 * k, l, (l + r) / 2);
      add(a, b, x, 2 * k + 1, (l + r) / 2, r);
    }
  }
  T get(int i) {
    add(i, i + 1);
    return d[n + i];
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Q, S, T;
  cin >> N >> Q >> S >> T;
  RangeAddQuery<int> segtree(N + 1);
  vector<int> A(N + 1, 0);
  rep(i, 0, N + 1) {
    cin >> A[i];
    segtree.d[segtree.n + i] = A[i];
  }

  int b = 0;
  rep(i, 1, N + 1) {
    if (A[i - 1] < A[i])
      b -= abs(A[i - 1] - A[i]) * S;
    else
      b += abs(A[i - 1] - A[i]) * T;
  }

  auto cal = [&](int a, int b) {
    int x = segtree.get(a), y = segtree.get(b);
    if (x < y)
      return -abs(x - y) * S;
    else
      return abs(x - y) * T;
  };

  vector<int> L(Q), R(Q), X(Q);
  rep(i, 0, Q) {
    cin >> L[i] >> R[i] >> X[i];
    b -= cal(L[i] - 1, L[i]);
    if (R[i] + 1 < N + 1)
      b -= cal(R[i], R[i] + 1);
    segtree.add(L[i], R[i] + 1, X[i]);

    b += cal(L[i] - 1, L[i]);
    if (R[i] + 1 < N + 1)
      b += cal(R[i], R[i] + 1);
    cout << b << endl;
  }

  return 0;
}
