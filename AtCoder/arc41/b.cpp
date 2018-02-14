#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
typedef __int128_t Int;
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
template <typename T> void printvv(vector<vector<T>> &vv) {
  rep(i, 0, vv.size()) {
    rep(j, 0, vv[0].size()) { cout << vv[i][j]; }
    cout << endl;
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  vector<vector<int>> b(N, vector<int>(M)), a(b);
  rep(i, 0, N) rep(j, 0, M) b[i][j] = v[i][j] - '0';

  int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

  rep(k, 1, (min(N, M) + 1) / 2) {
    rep(i, 0, M - k - 1) {
      int x = k, y = k + i;
      int s = INF;
      rep(j, 0, 4) { chmin(s, b[x + dx[j]][y + dy[j]]); }
      rep(j, 0, 4) { b[x + dx[j]][y + dy[j]] -= s; }
      a[x][y] += s;
    }
    rep(i, 0, N - k - 1) {
      int x = k + i, y = M - k - 1;
      int s = INF;
      rep(j, 0, 4) { chmin(s, b[x + dx[j]][y + dy[j]]); }
      rep(j, 0, 4) { b[x + dx[j]][y + dy[j]] -= s; }
      a[x][y] += s;
    }
    rep(i, 0, M - k - 1) {
      int x = N - k - 1, y = M - k - 1 - i;
      int s = INF;
      rep(j, 0, 4) { chmin(s, b[x + dx[j]][y + dy[j]]); }
      rep(j, 0, 4) { b[x + dx[j]][y + dy[j]] -= s; }
      a[x][y] += s;
    }
    rep(i, 0, N - k - 1) {
      int x = N - k - 1 - i, y = k;
      int s = INF;
      rep(j, 0, 4) { chmin(s, b[x + dx[j]][y + dy[j]]); }
      rep(j, 0, 4) { b[x + dx[j]][y + dy[j]] -= s; }
      a[x][y] += s;
    }
  }
  printvv(a);

  return 0;
}
