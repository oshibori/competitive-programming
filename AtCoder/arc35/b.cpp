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

  int N;
  cin >> N;
  vector<int> t(N + 1);
  rep(i, 1, N + 1) { cin >> t[i]; }
  vector<int> f(N + 1);
  f[0] = 1;
  rep(i, 1, N + 1)(f[i] = f[i - 1] * i) %= MOD;
  sort(all(t));
  int cost = 0;
  int tmp=0;
  rep(i, 1, N + 1) {
    tmp += t[i];
    cost += tmp;
  }
  map<int, int> m;
  rep(i, 1, N + 1) m[t[i]]++;
  t.erase(unique(all(t)), t.end());
  int cases = 1;
  dump(t);
  rep(i, 1, t.size())(cases *= f[m[t[i]]])%=MOD;

  cout << cost << endl << cases << endl;

  return 0;
}
