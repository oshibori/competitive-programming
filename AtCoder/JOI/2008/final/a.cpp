#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
  vector<int> v(N+1);
  rep(i, 1, N+1) { cin >> v[i]; }
  vector<int> dp(N + 1, 0);
  stack<int> s;
  rep(i, 1, N + 1) {
    if (i & 1) {
      dp[i] = dp[i - 1] + v[i];
      if (i!=1&&v[i] != v[i - 1])
        s.push(i - 1);
    } else {
      if (v[i] != v[i - 1]) {
        int x = (s.empty()?0:s.top());
        if(!s.empty())s.pop();
        dp[i] = dp[x] + v[i]+(i-1-x-1+1)*v[i];
      } else
        dp[i] = dp[i - 1] + v[i];
    }
  }
  dump(dp)
  cout << N-dp[N] << endl;

  return 0;
}
