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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  if (*max_element(all(A)) > 2000) {
    return 0;
  }
  vector<vector<int>> dp(N, vector<int>(A[N - 1] + 2, 0));
  dp[0][A[0]] = 1;
  rep(i, 0, N - 1) {
    if (A[i] != -1) {
      if (A[i + 1] != -1) {
        dp[i + 1][A[i + 1]] = dp[i][A[i]];
      } else {
        rep(j, A[i], dp[i+1].size()) { dp[i + 1][j] = dp[i][A[i]]; }
      }
    } else {
      if (A[i + 1] != -1) {
        dp[i + 1][A[i + 1]] =
            accumulate(dp[i].begin(), dp[i].begin() + A[i + 1] + 1, 0ll) % MOD;
      } else {
        rep(j, 0, dp[i + 1].size()) {
          (dp[i + 1][j] += dp[i][j]) %= MOD;
          (dp[i + 1][dp[i + 1].size() - 1] -= dp[i][j] + MOD) %= MOD;
        }
        rep(j, 1, dp[i + 1].size()) {
          (dp[i + 1][j] += dp[i + 1][j - 1]) %= MOD;
        }
      }
    }
  }
  printvv(dp);
  cout << dp[N - 1][A[N - 1]] << endl;

  return 0;
}
