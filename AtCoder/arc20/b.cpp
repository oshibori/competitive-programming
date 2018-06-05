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

  int N, C;
  cin >> N >> C;
  vector<int> a(N);
  rep(i, 0, N) {
    cin >> a[i];
    a[i]--;
  }
  int ans = INF;
  rep(x, 0, 10) rep(y, 0, 10) {
    if (x == y)
      continue;
    int tmp = 0;
    rep(i, 0, N) {
      if (i % 2 == 1 and a[i] != x)
        tmp++;
      else if (i % 2 == 0 and a[i] != y)
        tmp++;
    }
    chmin(ans, tmp * C);
    tmp = 0;
    rep(i, 0, N) {
      if (i % 2 == 1 and a[i] != y)
        tmp++;
      else if (i % 2 == 0 and a[i] != x)
        tmp++;
    }
    chmin(ans, tmp * C);
  }
  cout << ans << endl;

  return 0;
}
