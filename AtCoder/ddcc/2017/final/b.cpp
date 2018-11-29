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
using pii = pair<int, int>;
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
int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int lcm(const vector<int> &v) {
  int ret = v[0];
  for (int i = 1; i < v.size(); i++)
    ret = lcm(ret, v[i]);
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, Z;
  cin >> N >> Z;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  vector<int> d(N);
  rep(i, 0, N) { d[i] = gcd(a[i], Z); }
  cout << lcm(d) << endl;

  return 0;
}
