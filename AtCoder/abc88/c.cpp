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

  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 0, 3) rep(j, 0, 3) { cin >> c[i][j]; }

  vector<int> p{0, 1, 2}, sum;
  do {
    int tmp = 0, tmp2 = 0;
    rep(i, 0, 3) {
      tmp += c[i][p[i]];
      tmp2 += c[p[i]][i];
    }
    sum.push_back(tmp);
    sum.push_back(tmp2);
  } while (next_permutation(all(p)));

  bool f = true;
  rep(i, 0, sum.size()) {
    if (sum[i] != sum[0])
      f = false;
  }

  cout << (f ? "Yes" : "No") << endl;

  return 0;
}
