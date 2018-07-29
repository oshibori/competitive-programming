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
  vector<int> dp(N + 1, INF);
  dp[0] = 0;
  vector<int> v(1, 1);
  int six = 6;
  while (six <= N) {
    v.push_back(six);
    six *= 6;
  };
  int nine = 9;
  while (nine <= N) {
    v.push_back(nine);
    nine *= 9;
  };
  sort(all(v));

  dump(v.size());

  rep(i,0,v.size()){
    rep(j,v[i],dp.size()){
      chmin(dp[j],dp[j-v[i]]+1);
    }
  }
  cout<<dp[N]<<endl;


  return 0;
}
