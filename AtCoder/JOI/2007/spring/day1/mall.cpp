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
const int INF = 1e9;
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

  int M, N, A, B;
  cin >> M >> N >> A >> B;
  vector<vector<int>> C(N + 1, vector<int>(M + 1, 0));
  rep(i, 1, N + 1) rep(j, 1, M + 1) {
    cin >> C[i][j];
    if (C[i][j] == -1)
      C[i][j] = -INF;
  }
  rep(i, 1, N + 1) rep(j, 1, M + 1) C[i][j] +=
      C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];

  int ans = INF;
  for (int i = 1; i + B - 1 < N + 1; i++)
    for (int j = 1; j + A - 1 < M + 1; j++) {
      // i,j i+b-1,j i,j+a-1, i+b-1,j+a-1
      int x = C[i + B - 1][j + A - 1] + C[i - 1][j - 1] - C[i + B - 1][j - 1] -
              C[i - 1][j + A - 1];
      if (x >= 0)
        chmin(ans, x);
    }
  cout << ans << endl;

  return 0;
}
