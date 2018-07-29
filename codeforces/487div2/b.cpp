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

  int N, P;
  cin >> N >> P;
  string s;
  cin >> s;

  bool f = false;
  rep(i, 0, s.size() - P) {
    if (s[i] == '.') {
      f = true;
      if (s[i + P] == '0')
        s[i] = '1';
      else if (s[i + P] == '1')
        s[i] = '0';
      else {
        s[i] = '0';
        s[i + P] = '1';
      }
      break;

    } else {
      if (s[i] != s[i + P]) {
        f = true;
        if (s[i + P] == '.') {
          if (s[i] == '0')
            s[i + P] = '1';
          else
            s[i + P] = '0';
        }
        break;
      }
    }
  }

  rep(i, 0, s.size()) {
    if (s[i] == '.')
      s[i] = '0';
  }

  if (f) {
    cout << s << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
