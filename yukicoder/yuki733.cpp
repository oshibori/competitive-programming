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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int T;
  cin >> T;
  int N;
  cin >> N;
  vector<int> t(N);
  rep(i, 0, N) { cin >> t[i]; }
  vector<vector<int>> dp(1 << N, vector<int>(N + 1, INF));
  rep(i, 1, N + 1) dp[0][i] = 0;
  rep(bits, 0, 1 << N) {
    int sum = 0;
    rep(i, 0, N) {
      if (bits >> i & 1)
        sum += t[i];
    }
    dp[bits][0] = sum;
  }

  rep(bits, 1, 1 << N) rep(i, 1, N + 1) {
    if (dp[bits][i - 1] <= T)
      dp[bits][i] = 0;
    else {
      rep(j, 0, N) {
        if (bits >> j & 1) {
          chmin(dp[bits][i], dp[bits ^ (1 << j)][i] + t[j]);
        }
      }
    }
  }
  int ans = N;
  rep(i, 0, N) if (dp[(1 << N) - 1][i] == 0) chmin(ans, i);
  cout << ans << endl;

  return 0;
}
