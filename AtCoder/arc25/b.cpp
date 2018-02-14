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
  vector<vector<int>> b(H + 1, vector<int>(W + 1)), w(b);
  rep(i, 1, H + 1) rep(j, 1, W + 1) {
    if ((i + j) % 2 == 0) {
      cin >> b[i][j];
    } else {
      cin >> w[i][j];
    }
  }
  rep(i, 1, H + 1) rep(j, 1, W + 1) {
    b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    w[i][j] += w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
  }

  int ans = 0;
  rep(i, 1, H + 1) rep(j, 1, W + 1) rep(k, i, H + 1) rep(l, j, W + 1) {
    int sumb = b[k][l] + b[i - 1][j - 1] - b[k][j - 1] - b[i - 1][l];
    int sumw = w[k][l] + w[i - 1][j - 1] - w[k][j - 1] - w[i - 1][l];
    if (sumb == sumw) {
      chmax(ans, (k - i + 1) * (l - j + 1));
    }
  }
  cout << ans << endl;

  return 0;
}
