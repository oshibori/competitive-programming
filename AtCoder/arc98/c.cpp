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

  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<int> v(N), w(N);
  v[0] = (s[0] == 'W');
  w[N - 1] = (s[N - 1] == 'E');

  rep(i, 1, N) { v[i] = (v[i - 1] + (s[i] == 'W')); }
  rrep(i, 0, N - 1) { w[i] = (w[i + 1] + (s[i] == 'E')); }

  dump(v, w);
  int ans = min(w[0], v[N - 1]);
  rep(i, 1, N - 1) { chmin(ans, v[i - 1] + w[i + 1]); }
  cout << ans << endl;

  return 0;
}
