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
  vector<vector<int>> D(C, vector<int>(C));
  rep(i, 0, C) rep(j, 0, C) { cin >> D[i][j]; }
  vector<vector<int>> c(N, vector<int>(N));
  rep(i, 0, N) rep(j, 0, N) {
    cin >> c[i][j];
    c[i][j]--;
  }
  vector<vector<int>> v(3, vector<int>(C));
  rep(x, 0, N) rep(y, 0, N) { v[(x + y) % 3][c[x][y]]++; }

  int ans = INF;
  rep(i, 0, C) rep(j, 0, C) rep(k, 0, C) {
    if (i == j or j == k or k == i)
      continue;
    int tmp = 0;
    dump(i, j, k);

    rep(l,0,C){
      tmp+=v[0][l]*D[l][i];

      tmp+=v[1][l]*D[l][j];

      tmp+=v[2][l]*D[l][k];
    }

    dump(tmp);
    chmin(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
