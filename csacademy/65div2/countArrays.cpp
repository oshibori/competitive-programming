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
long long modpow(long long base, long long exponent, long long mod = MOD) {
  long long res = 1;
  while (exponent > 0) {
    if (exponent & 1)
      res = res * base % mod;
    base = base * base % mod;
    exponent >>= 1;
  }
  return res;
}
int dfs(vector<pair<int, int>> &w, int x) {
  if(x==w.size())return 1;
  int ret = 1;
  if (w[x].second == 0) {
    ret *= modpow(2, w[x].first) - 1;
    ret %= MOD;
    rep(i, x + 1, w.size())(ret *= modpow(2, w[i].first)) %= MOD;
    (ret += dfs(w, x + 1)) %= MOD;
  } else {
    (ret *= modpow(2, w[x].first)) %= MOD;
    (ret *= dfs(w, x + 1)) %= MOD;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;
  vector<int> v(N + 2, 0);
  loop(Q) {
    int l, r;
    cin >> l >> r;
    v[l]++;
    v[r + 1]--;
  }
  rep(i, 1, N + 2) v[i] += v[i - 1];
//  rep(i, 0, N + 2) v[i] = v[i] >= 1;
  dump(v);
  vector<int>dp(N+1,0);
  dp[0]=1;


  vector<pair<int, int>> w;
  int i = 1;
  while (i < N + 1) {
    int j = 0;
    while (i + j + 1 < N + 1 and v[i + j] == v[i + j + 1])
      j++;
    w.push_back(make_pair(j + 1, !v[i]));
    i += j + 1;
  }
  dump(w);
  cout<<dfs(w,0)%MOD<<endl;

  return 0;
}
