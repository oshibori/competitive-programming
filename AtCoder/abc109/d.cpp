#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

  int H, W;
  cin >> H >> W;
  vector<vector<int>> v(H, vector<int>(W));
  rep(i, 0, H) rep(j, 0, W) { cin >> v[i][j]; }
  auto np = [&](pii p) {
    int x = p.fi, y = p.se;
    if (y == W - 1 and x % 2 == 0)
      p.fi++;
    else if (y == 0 and x % 2 == 1)
      p.fi++;
    else if(x%2==0)
      p.se++;
    else if(x%2==1)p.se--;
    return p;
  };
  vector<pair<pii, pii>> ans;
  pii p(0, 0);
  loop(H * W - 1) {
    int x = p.fi, y = p.se;
    auto a = np(p);
    int f = a.fi, g = a.se;
    if (v[x][y] & 1) {
      ans.emplace_back(make_pair(p, np(p)));
      v[x][y]--;
      v[f][g]++;
    }
    p = a;
  }
  dump(v);

  cout << ans.size() << endl;
  for (auto ff : ans) {
    cout << ff.fi.fi+1 << " " << ff.fi.se+1 << " " << ff.se.fi+1 << " " << ff.se.se+1
         << endl;
  }

  return 0;
}
