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
void ppp(vector<vector<int>>&x){
  cout<<endl;
  rep(i,0,x.size())rep(j,0,x[0].size())
    cout<<x[i][j]<<(j==x[0].size()-1?'\n':' ');
  cout<<endl;cout<<endl;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T, S;
  cin >> N >> T >> S;
  vector<int> a(N + 1), b(N + 1);
  rep(i, 1, N + 1) { cin >> a[i] >> b[i]; }
  vector<vector<int>> dp1(N + 1, vector<int>(S + 1, -INF));
  rep(i, 0, S + 1) { dp1[0][i] = 0; }
  rep(i, 1, N + 1) rep(j, 0, S + 1) {
    dp1[i][j] = dp1[i - 1][j];
    if (j - b[i] >= 0)
      chmax(dp1[i][j], dp1[i - 1][j - b[i]] + a[i]);
  }
  if(DBG){
    ppp(dp1);
  }

  a.push_back(0);
  b.push_back(0);
  reverse(all(a));
  reverse(all(b));
  vector<vector<int>> dp2(N + 1, vector<int>(T - S + 1, -INF));
  rep(i, 0, T - S + 1) { dp2[0][i] = 0; }
  rep(i, 1, N + 1) rep(j, 0, T - S + 1) {
    dp2[i][j] = dp2[i - 1][j];
    if (j - b[i] >= 0)
      chmax(dp2[i][j], dp2[i - 1][j - b[i]] + a[i]);
  }
  if(DBG){
    ppp(dp2);
  }

  int ans = -INF;
  rep(k, 1, N) chmax(ans, dp1[k][S] + dp2[N - k][T - S]);
  cout << ans << endl;

  return 0;
}
