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

  int N, C;
  cin >> N >> C;
  vector<vector<pair<int, int>>> v(C);
  rep(i, 0, N) {
    int a, b, c;
    cin >> a >> b >> c;
    c--;
    v[c].push_back(make_pair(a, b));
  }
  vector<int> imos(1e5 + 10, 0);
  rep(i, 0, C) {
    if(v[i].empty())continue;
    sort(all(v[i]));
    int b = 1;
    rep(j, 1, v[i].size()) {
      if (v[i][b - 1].second == v[i][j].first) {
        v[i][b - 1].second = v[i][j].second;
      } else {
        v[i][b++] = v[i][j];
      }
    }
    rep(j, 0, b) { imos[v[i][j].first - 1]++, imos[v[i][j].second]--; }
  }
  rep(i, 1, imos.size()) imos[i] += imos[i - 1];

  cout << *max_element(all(imos)) << endl;

  return 0;
}
