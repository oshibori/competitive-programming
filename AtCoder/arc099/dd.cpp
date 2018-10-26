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

int S(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
#define eb emplace_back
#define MAX 1e3
vector<int> aaa(vector<double> &v) {
  double mi = v.back();
  vector<int> ans;
  rrep(i, 1, v.size()) {
    if (v[i] <= mi) {
      dump(i, S(i), v[i]);
      ans.eb(i);
    }
    chmin(mi, v[i]);
  }
  reverse(all(ans));
  return ans;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int K;
  cin >> K;

  vector<double> v(MAX);
  rep(i, 1, MAX) { v[i] = (double)i / S(i); }
  auto ans = aaa(v);
  rep(i, 4, 17) {
    int x = i - 3;
    string s;
    loop(i - 2) { s += "9"; }
    rep(a, 10, (x + 1) * 10) {
      dump(to_string(a) + s);
      ans.eb(stoll(to_string(a) + s));
    }
    rep(a, x + 1, 10) { ans.eb(stoll(to_string(a) + "9" + s)); }
  }

  vector<int> f;
  double mi = (double)ans.back() / S(ans.back());
  rrep(i, 0, ans.size()) {
    if ((double)ans[i] / S(ans[i]) <= mi) {
      f.eb(ans[i]);
    }
    chmin(mi, (double)ans[i] / S(ans[i]));
  }

  rep(i, 0, K) { cout << ans[i] << endl; }

  return 0;
}
