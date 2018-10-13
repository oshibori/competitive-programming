#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
#define fi first
#define se second
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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
int N, K;
int dp[55][2][5000];
int dfs(vector<int> &a, int x, bool zero, int remain) {
  if (x >= N) {
    if (zero or remain == 0)
      return 1;
    else
      return 0;
  }
  if (dp[x][zero][remain] != -1) {
    return dp[x][zero][remain];
  }
  int ret = 0;
  rep(i, 0, min(a[x], remain) + 1) {
    (ret += dfs(a, x + 1, zero | (i == a[x]), remain - i)) %= MOD;
  }
  return dp[x][zero][remain] = ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  cin >> N >> K;
  rep(i, 0, 55) rep(j, 0, 2) rep(k, 0, 5000) { dp[i][j][k] = -1; }
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  vector<int> a(N);
  rep(i, 0, N) {
    int cnt = 0;
    while (v[i]) {
      v[i] >>= 1;
      cnt++;
    }
    a[i] = cnt;
  }
  dump(a);
  K = min(accumulate(all(a), 0ll), K);
  cout << dfs(a, 0, false, K) << endl;

  return 0;
}
