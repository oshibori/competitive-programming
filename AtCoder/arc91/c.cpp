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

int N, M;
bool inrange(int x, int y) { return 0 <= x and x < N and 0 <= y and y < M; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  int ans = 0;
  if (N == 1 and M == 1) {
    ans = 1;
  } else if (N == 1) {
    ans += max(0ll, M - 2);
  } else if (M == 1) {
    ans += max(0ll, N - 2);
  } else if (N >= 3 and M >= 3) {

    ans += max(0ll, N - 2) * max(0ll, M - 2);
  } else {
    vector<vector<int>> v(N, vector<int>(M, 0));
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    rep(i, 0, N) rep(j, 0, M) {
      v[i][j]++;
      rep(k, 0, 8) {
        int x = i + dx[k], y = j + dy[k];
        if (inrange(x, y))
          v[x][y]++;
      }
    }
    rep(i, 0, N) rep(j, 0, M) if (v[i][j] & 1) ans++;
  }

  cout << ans << endl;
  return 0;
}
