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

int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int T;
  cin >> T;
  rep(cnt, 0, T) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans = "Yes";

    if (a < b) {
      ans = "No";
    } else {
      if (b > d) {
        ans = "No";
      } else {
        if (b <= c) {
          ans = "Yes";
        } else if ((b - gcd(b, d) + a % gcd(b, d)) > c) {
          ans = "No";
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
