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

int f(string &s, int k) {
  int i = 0;
  int n = s.size();
  int ret = 0;
  while (i < n) {
    int cnt = 0;
    while (i < n and s[i] == '.') {
      cnt++, i++;
    }
    ret += max(0, cnt - k + 1);
    i++;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }

  int ans = 0;
  if(K!=1)rep(i, 0, N) { ans += f(v[i], K); }
  rep(i, 0, M) {
    string a;
    rep(j, 0, N) a.push_back(v[j][i]);
    ans += f(a, K);
  }
  cout << ans << endl;

  return 0;
}
