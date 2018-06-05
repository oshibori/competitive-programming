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

  int H, W;
  cin >> H >> W;
  vector<string> v(H);
  rep(i, 0, H) { cin >> v[i]; }
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < H and 0 <= y and y < W;
  };
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  bool ans = true;

  rep(i, 0, H) rep(j, 0, W) {
    if (v[i][j] == '.')
      continue;

    bool f = false;
    rep(k, 0, 4) {
      int a = i + dx[k], b = j + dy[k];
      if (inrange(a, b)) {
        dump(inrange(a, b), a, b);
        f |= (v[a][b] == '#');
      }
    }

    ans &= f;
  }

  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}
