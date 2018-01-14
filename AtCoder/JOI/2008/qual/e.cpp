#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  int R, C;
  cin >> R >> C;
  int ans = 0;
  vector<vector<int>> a(R, vector<int>(C));
  rep(i, 0, R) rep(j, 0, C) { cin >> a[i][j]; }

  for (int S = 0; S < (1 << R); S++) {
    int cnt = 0;
    rep(i, 0, C) {
      int w = 0;
      rep(j,0,R)w+=(a[j][i]+(S>>j)&1)%2;
      cnt+=max(w,R-w);
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}
