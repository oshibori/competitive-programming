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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  /*
    rep(i, 0, 15) rep(j, 0, 15) {
      if (i == 0)
        continue;
      cout << j % i << (j == 14 ? '\n' : ' ');
    }

    */
  int N, K;
  cin >> N >> K;

  int ans = 0;
  rep(b, 1, N + 1) {
    ans += ((N + 1) / b) * max(b - K, 0ll);
    if ((N + 1) % b - 1 >= K) {
      ans += (N + 1) % b - K;
    }
    dump(b, ans);
  }
  if (K == 0)
    ans -= N;
  cout << ans << endl;

  return 0;
}
