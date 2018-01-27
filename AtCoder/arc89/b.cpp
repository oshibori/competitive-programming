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

  int N, K;
  cin >> N >> K;
  int x, y;
  char c;
  vector<vector<int>> v(4 * K, vector<int>(4 * K, 0));
  rep(i, 0, N) {
    cin >> x >> y >> c;
    if (c == 'W') {
      x += K;
    }
    x %= 2 * K;
    y %= 2 * K;

    v[x][y]++;
    v[x + 2 * K][y]++;
    v[x][y + 2 * K]++;
    v[x + 2 * K][y + 2 * K]++;
  }

  rep(i, 1, v.size()) rep(j, 1, v[0].size()) v[i][j] +=
      v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
  if(DBG){
    rep(i,0,v.size())rep(j,0,v[0].size())cout<<v[i][j]<<(j==v[0].size()-1?'\n':' ');
  }

  auto get = [&](int a, int b, int c, int d) {
    return v[c][d]-v[c][b]-v[a][d]+v[a][b];
  };
  int ans = 0;
  rep(i, 0, 2 * K) rep(j, 0, 2 * K) {
    int sum = get(i, j, i + K, j + K) + get(i + K, j + K, i + 2 * K, j + 2 * K);
    dump(sum);
    chmax(ans, max(N - sum, sum));
  }

  cout << ans << endl;
  return 0;
}
