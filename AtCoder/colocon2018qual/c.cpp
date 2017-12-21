#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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
//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }
//最大公約数 複数個
int gcd(const vector<int> &v) {
  int ret = v[0];
  for (int i = 1; i < v.size(); i++)
    ret = gcd(ret, v[i]);
  return ret;
}
int A, B;
map<int, pair<int, int>> m;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> B;

  int odd = 0, even = 0;
  vector<int> o, e;
  rep(i, A, B + 1) {
    if (i % 2) {
      odd++;
      o.push_back(i);
    } else {
      even++;
      e.push_back(i);
    }
  }
  int ans(even + 1);
  if (A % 2 == 0)
    A++;
  for (int i = 1; i < (1 << odd); i++) {
    vector<int> v;
    int s = A;
    rep(j, 0, odd) {
      if (i & (1 << j))
        v.push_back(s);
      s += 2;
    }
    bool g(false);
    rep(x, 0, v.size())
        rep(y, x + 1, v.size()) if (gcd(v[x], v[y]) != 1) g = true;
    if (g)
      continue;
    if (v.size() == 1 || gcd(v) == 1) {
      int m(0);
      rep(x, 0, e.size()) {
        bool f = false;
        rep(y, 0, v.size()) {
          if (gcd(e[x], v[y]) != 1)
            f = true;
        }
        if (f)
          m++;
      }
      ans += 1 + even - m;
    }
  }
  cout << ans << endl;

  return 0;
}
