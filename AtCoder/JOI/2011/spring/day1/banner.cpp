#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
int H, W;
bool inrange(int x, int y) { return 0 <= x and x < H and 0 <= y and y < W; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  const int N = 400;

  cin >> H >> W;
  static int v[N][N];
  rep(i, 0, H) rep(j, 0, W) { cin >> v[i][j]; }
  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
  int ans = 0;
  rep(a, 0, H) rep(b, 0, W) {
    map<int, int> p[4];
    rep(i, 0, 4) {
      int x = a + dx[i], y = b + dy[i];
      while (inrange(x, y)) {
        p[i][v[x][y]]++;
        x += dx[i], y += dy[i];
      }
    }
    rep(i, 0, 4) {
      rep(x, 0, 3) rep(y, 0, 3) {
        if (v[a][b] != x and v[a][b] != y and x != y)
          ans += p[i][x] * p[(i + 1) % 4][y];
      }
    }
  }
  cout << ans / 2 << endl;

  return 0;
}
