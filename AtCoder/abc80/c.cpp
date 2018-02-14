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

  int N;
  cin >> N;
  vector<bitset<10>> f(N);
  rep(i, 0, N) {
    rrep(j, 0, 10) {
      int a;
      cin >> a;
      f[i][j] = a;
    }
  }
  vector<vector<int>> p(N, vector<int>(11));
  rep(i, 0, N) rep(j, 0, 11) { cin >> p[i][j]; }

  int ans = -INF;
  rep(bits, 1, (1 << 10)) {
    bitset<10> b(bits);
    int score = 0;
    rep(i, 0, N) { score += p[i][(b & f[i]).count()]; }
    chmax(ans, score);
  }

  cout << ans << endl;

  return 0;
}
