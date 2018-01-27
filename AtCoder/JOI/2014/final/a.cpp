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

  int N, M;
  cin >> N >> M;
  char flag[1010][1010];
  rep(i, 0, N) rep(j, 0, M) { cin >> flag[i][j]; }
  vector<string> mark(2);
  rep(i, 0, 2) { cin >> mark[i]; }
  int ans = 0;
  auto check = [&](int x, int y) {
    return mark[0][0] == flag[x][y] and
           mark[0][1] == flag[x][y + 1] and mark[1][0] == flag[x + 1][y] and
           mark[1][1] == flag[x + 1][y + 1];
  };
  int dx[] = {0, -1, -1, 0}, dy[] = {0, 0, -1, -1};
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < N and 0 <= y and y < M;
  };
  auto calc = [&](int x, int y) {
    int ret = 0;
    rep(i, 0, 4) {
      int a = x + dx[i], b = y + dy[i];
      if (inrange(a, b) and inrange(a + 1, b + 1))
        ret += check(a, b);
    }
    return ret;
  };
  int sum = 0;
  rep(i, 0, N - 1) rep(j, 0, M - 1) sum += check(i, j);
  vector<char> joi = {'J', 'O', 'I'};
  rep(i, 0, N) rep(j, 0, M) {
    int x = calc(i, j);

    char c = flag[i][j];
    rep(k, 0, 3) {
      flag[i][j] = joi[k];
      chmax(ans, calc(i, j) - x);
    }
    flag[i][j] = c;
  }
  cout << sum + ans << endl;

  return 0;
}
