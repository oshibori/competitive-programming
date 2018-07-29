#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  string s;
  cin >> s;
  string t;
  rep(i, 0, s.size() * 2 + 1) {
    if (i & 1) {
      t += s.substr(i / 2, 1);
    } else {
      t += "$";
    }
  }
  dump(t);
  string g(s);
  reverse(all(g));

  int ans = INF;
  if (s == g)
    ans = 0;
  rep(i, (int)t.size() / 2, t.size()) {
    int x = i, y = i;
    int c = 0;
    while (c < min(i, (int)t.size() - i - 1) + 1 and t[x] == t[y]) {
      x--, y++, c++;
    }
    dump(i, c);
    if (c == min(i, (int)t.size() - i - 1) + 1) {
      if (t[i] == '$') {
        chmin(ans, i / 2 - c / 2 );
      } else {
        chmin(ans, (i + 1) / 2 - c / 2 );
      }
    }
  }
  cout << ans << endl;

  return 0;
}
