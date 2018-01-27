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

int f(vector<int> &a, int x) {
  rep(i, 0, a.size()) { x = x / a[i] * a[i]; }
  return x;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K;
  cin >> K;
  vector<int> A(K);
  rep(i, 0, K) { cin >> A[i]; }
  if (DBG) {
    rep(i, 2, 200) { dump(i, f(A, i)); }
  }

  int l = 1, r = INF;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (f(A, m) == 0)
      l = m;
    else
      r = m;
  }
  int x = r;
  int y = INF;

  if (f(A, r) != 2) {
    cout << -1 << endl;
  } else {
    while (y - x > 1) {
      int m = (y + x) / 2;
      if (f(A, m) == 2)
        x = m;
      else
        y = m;
    }
    cout << r << " " << x << endl;
  }

  return 0;
}
