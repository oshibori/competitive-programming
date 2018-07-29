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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> ans(N);
  int re = 0;
  while (re < N) {
    int x = min(10ll, N - re);
    dump(x);
    string query = "?";
    rep(i, 0, re) { query += " 0"; }
    int five = 1;
    int sum=0;
    rep(i, re, re + x) {
      query += " " + to_string(five);
      sum+=five;
      five *= 5;
    }
    dump(sum);
    rep(i, re + x, N) { query += " 0"; }
    cout << query << endl;
    int y;
    cin >> y;
    y -= 8 * sum;
    rep(i, 0, x) {
      ans[re + i] = y % 5;
      y /= 5;
    }
    re += x;
  }
  string out = "!";
  rep(i, 0, N) { out += " " + to_string(ans[i] & 1); }
  cout << out << endl;

  return 0;
}
