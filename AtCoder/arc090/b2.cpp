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
struct info {
  int l, r, d;
  info(int l, int r, int d) : l(l), r(r), d(d) {}
  bool operator<(info &o) {
    return (l != o.l ? l < o.l : (r != o.r ? r < o.r : (d < o.d)));
  }
};
ostream &operator<<(ostream &os, info &o) {
  os << o.l << " " << o.r << " " << o.d;
  return os;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<info> v;
  rep(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v.push_back(info(a, b, c));
    v.push_back(info(b, a, -c));
  }
  sort(all(v));
  M*=2;

  map<int, int> m, inv;
  rep(i, 0, M) {
    int l = v[i].l, r = v[i].r, d = v[i].d;
    dump(v[i]);

    if (!m.count(l) and !m.count(r)) {
      m[l] = 0;
      m[r] = d;
    } else if (!m.count(l)) {
      m[l] = m[r] - d;
    } else if (!m.count(r)) {
      m[r] = m[l] + d;
    } else {
      if (m[l] + d != m[r]) {
        cout << "No" << endl;
        return 0;
      }
    }
    dump(m);
  }
  rep(i, 0, M) {
    int l = v[i].l, r = v[i].r, d = v[i].d;
    if (m[l] + d != m[r]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
