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
  int T;
  cin >> T;
  vector<int> W(N);
  rep(i, 0, N) { cin >> W[i]; }
  vector<string> s(T);
  rep(i, 0, T) { cin >> s[i]; }

  vector<vector<int>> dp(T + 1, vector<int>(1 << N));
  rep(i, 0, T) {
    rep(bits, 0, 1 << N) {
      int l = 0, r = 0;
      rep(j, 0, N) {
        if ((bits >> j) & 1)
          r += W[j];
        else
          l += W[j];
      }
      bool f = false;
      f |= (s[i] == "<" and l < r);
      f |= (s[i] == ">" and l > r);
      f |= (s[i] == ">=" and l >= r);
      f |= (s[i] == "<=" and l <= r);

      if(f){
        dp[i+1][bits]+=dp[i][bits];
        rep(j,0,N){
          if((bits>>j)&1){

          }
        }
      }
    }
  }

  return 0;
}
