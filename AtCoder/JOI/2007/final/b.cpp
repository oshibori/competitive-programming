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

bool operator<(pair<int, int> x, pair<int, int> y) {
  int a = abs(x.first - x.second), b = abs(y.first - y.second);
  return a < b;
}

ostream &operator<<(ostream &os, pair<int, int> x) {
  //return os << "(" << x.first << "," << x.second << ")";
  return os << x.second - x.first + 1;
}

pair<int, int> operator+(pair<int, int> x, pair<int, int> y) {
  if (x.second == y.first - 2)
    return make_pair(x.first, y.second);
  else {
    chmax(x, y);
    return (make_pair(x.first, x.second + 1));
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<int> v(K);
  rep(i, 0, K) { cin >> v[i]; }
  vector<pair<int, int>> w;
  w.push_back(make_pair(INF, INF));
  sort(all(v));
  int i = v[0] == 0 ? 1 : 0;
  while (i < K) {
    int j = 0;
    while (i + j + 1 < K && v[i + j] == v[i + j + 1] - 1)
      j++;
    w.push_back(make_pair(v[i], v[i + j]));
    i += j + 1;
  }
  dump(w);

  auto ans = *max_element(all(w), [&](pair<int, int> x, pair<int, int> y) {
    int a = abs(x.first - x.second), b = abs(y.first - y.second);
    return a < b;
  });
  dump(ans);
  if (v[0] == 0)
    rep(i, 0, w.size() - 1) {
      chmax(ans, w[i] + w[i + 1]);
      dump(w[i] + w[i + 1]);
    }

  cout << ans << endl;

  return 0;
}
