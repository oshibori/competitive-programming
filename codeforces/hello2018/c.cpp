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

  int N, L;
  cin >> N >> L;
  vector<int> c(N), p(N);
  p[0] = 1;
  rep(i, 0, N) { cin >> c[i]; }

  rep(i, 1, N) p[i] = 2 * p[i - 1];
  rep(i, 1, N) chmin(c[i], c[i - 1] * 2);

  int ans = INF;
  int basis = 0;

  if (L >= p[N - 1]) {
    basis += (L / p[N - 1]) * c[N - 1];
    L %= p[N - 1];
  }

  for (; L <= p[N - 1]; L += (L & -L)) {
    int t = 0;
    int _L = L;
    int i = 0;
    while (_L) {
      if (_L & 1)
        t += c[i];
      i++;
      _L >>= 1;
    }
    chmin(ans,t);
  }

  cout << ans+basis << endl;

  return 0;
}
