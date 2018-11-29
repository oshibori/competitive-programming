#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
// typedef __int128_t Int;
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
// source http://satanic0258.hatenablog.com/entry/2016/08/16/181331
// https://yukicoder.me/problems/no/703
// addの直線の傾きの単調性が保証されている
class ConvexHullTrick {
public:
  deque<pair<int, int>> lines;
  // queryのxの単調性が保証されているとき、true
  bool isMonotonic = false;
  function<bool(int, int)> comp = [](int l, int r) {
    return l >= r; // min
    // return l <= r; // max
  };

  // l1,l2,l3のうち、l2が不必要であるかどうか
  bool check(pair<int, int> l1, pair<int, int> l2, pair<int, int> l3) {
    if (l1 < l3)
      swap(l1, l3);
    int a1 = l1.first, b1 = l1.second;
    int a2 = l2.first, b2 = l2.second;
    int a3 = l3.first, b3 = l3.second;
    return (a2 - a3) * (b1 - b2) <= (a1 - a2) * (b2 - b3);
  }
  void add(int a, int b) {
    pair<int, int> line(a, b);
    while (lines.size() >= 2 and
           check(lines[lines.size() - 2], lines[lines.size() - 1], line)) {
      lines.pop_back();
    }
    lines.emplace_back(line);
  }
  int f(int j, int x) { return lines[j].first * x + lines[j].second; }

  int query(int x) {
    if (isMonotonic) {
      while (lines.size() >= 2 and comp(f(0, x), f(1, x))) {
        lines.pop_front();
      }
      return f(0, x);
    } else {
      int l = 0, r = lines.size();
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (comp(f(m - 1, x), f(m, x))) {
          l = m;
        } else {
          r = m;
        }
      }
      return f(l, x);
    }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> x(N);
  rep(i, 0, N) { cin >> x[i]; }
  vector<int> y(N);
  rep(i, 0, N) { cin >> y[i]; }

  ConvexHullTrick cht;

  vector<int> dp(N + 1);
  dp[0] = 0;
  rep(i, 1, N + 1) {
    cht.add(-2 * x[i - 1],
            dp[i - 1] + x[i - 1] * x[i - 1] + y[i - 1] * y[i - 1]);

    dp[i] = a[i - 1] * a[i - 1] + cht.query(a[i - 1]);
  }
  cout << dp[N] << endl;

  return 0;
}
