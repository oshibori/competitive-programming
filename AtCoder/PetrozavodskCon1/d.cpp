#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
typedef __int128_t Int;
typedef pair<int, int> P;
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

template <typename T> class DisjointSet {
public:
  vector<T> rank, p;
  int SizeOfCC;
  vector<P> minimum;

  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, 0, size) makeSet(i);
    SizeOfCC = size;
    minimum.resize(size);
  }
  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }
  bool same(int x, int y) { return findSet(x) == findSet(y); }
  void unite(int x, int y) {
    if (same(x, y))
      return;
    link(findSet(x), findSet(y));
  }
  void link(int x, int y) {
    SizeOfCC--;
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
    if (minimum[x].first < minimum[y].first) {
      minimum[y] = minimum[x];
    } else
      minimum[x] = minimum[y];
  }
  int findSet(int x) {
    if (x != p[x]) {
      p[x] = findSet(p[x]); // path compression
    }
    return p[x];
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  rep(i, 0, N) { cin >> a[i]; }
  DisjointSet<int> uf(N);
  rep(i, 0, N) { uf.minimum[i] = P(a[i], i); }
  rep(i, 0, M) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  if (uf.SizeOfCC == 1) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  set<P> s;
  rep(i, 0, N) {
    auto h = uf.minimum[uf.findSet(i)];
    s.insert(h);
  }
  vector<P> v;
  rep(i, 0, N) {
    if (s.count(P(a[i], i)))
      continue;
    v.push_back(P(a[i], i));
  }
  sort(all(v));

  for (auto &o : s) {
    ans += o.first;
  }

  if (v.size() < uf.SizeOfCC - 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  rep(i, 0, uf.SizeOfCC - 2) { ans += v[i].first; }

  cout << ans << endl;

  return 0;
}
