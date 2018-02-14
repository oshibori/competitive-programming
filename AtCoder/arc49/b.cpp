#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
typedef __int128_t Int;
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
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<double> x(N), y(N), c(N);
  rep(i, 0, N) cin >> x[i] >> y[i] >> c[i];

  auto f = [&](double t) {
    rep(i, 0, N) rep(j, i + 1, N) {
      double dx = abs(x[i] - x[j]), dy = abs(y[i] - y[j]);
      if (dx > t / c[i] + t / c[j] or dy > t / c[i] + t / c[j])
        return false;
    }
    return true;
  };
  double l = 0, r = 1e12;
  loop(100) {
    double m = (l + r) / 2;
    if (f(m))
      r = m;
    else
      l = m;
  }
  cout << l << endl;

  return 0;
}
