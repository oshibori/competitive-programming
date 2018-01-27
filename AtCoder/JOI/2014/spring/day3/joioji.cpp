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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s;
  cin >> s;
  map<tuple<int, int, int>, int> m;
  m[make_tuple(0, 0, 0)] = 0;
  vector<vector<int>> v(N + 1, vector<int>(3, 0));
  int ans = 0;
  rep(i, 1, N + 1) {
    if (s[i - 1] == 'J')
      v[i][0] += 1;
    if (s[i - 1] == 'O')
      v[i][1] += 1;
    if (s[i - 1] == 'I')
      v[i][2] += 1;

    rep(j, 0, 3) v[i][j] += v[i - 1][j];
    auto t =
        make_tuple(v[i][0] - v[i][1], v[i][1] - v[i][2], v[i][2] - v[i][0]);

    if (m.count(t)) {
      chmax(ans, v[i][0] - v[m[t]][0]);
    } else {
      m[t] = i;
    }
  }
  cout<<ans*3<<endl;

  return 0;
}
