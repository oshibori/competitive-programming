#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
/*
   typedef __int128_t Int;
   std::ostream &operator<<(std::ostream &dest, __int128_t value) {
   std::ostream::sentry s(dest);
   if (s) {
   __uint128_t tmp = value < 0 ? -value : value;
   char buffer[128];
   char *d = std::end(buffer);
   do {
   --d;
 *d = "0123456789"[tmp % 10];
 tmp /= 10;
 } while (tmp != 0);
 if (value < 0) {
 --d;
 *d = '-';
 }
 int len = std::end(buffer) - d;
 if (dest.rdbuf()->sputn(d, len) != len) {
 dest.setstate(std::ios_base::badbit);
 }
 }
 return dest;
 }

 __int128 parse(string &s) {
 __int128 ret = 0;
 for (int i = 0; i < s.length(); i++)
 if ('0' <= s[i] && s[i] <= '9')
 ret = 10 * ret + s[i] - '0';
 return ret;
 }
 */

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
using Weight = int;
using Flow = int;
struct Edge {
  int s, d;
  Weight w;
  Flow c;
  Edge(){};
  Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w){};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) {
  return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')');
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

inline ostream &operator<<(ostream &os, const Edges &es) {
  os << "[";
  for (int i = 0; i < es.size(); i++) {
    os << es[i] << (i == es.size() - 1 ? "" : ", ");
  }
  os << "]";
  return os;
}
inline ostream &operator<<(ostream &os, const Graph &g) {
  os << "{";
  for (int i = 0; i < g.size(); i++) {
    os << g[i] << (i == g.size() - 1 ? "" : ", ");
  }
  os << "}";
  return os;
}
void addArc(Graph &g, int s, int d, Weight w = 1) {
  g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
  addArc(g, a, b, w);
  addArc(g, b, a, w);
}

vector<int> dijkstra(const Graph &g, int s, Array &dist) {
  int n = g.size();
  assert(s < n);
  enum { WHITE, GRAY, BLACK };
  vector<int> color(n, WHITE);
  color[s] = GRAY;
  vector<int> prev(n, -1);
  dist.assign(n, INF);
  dist[s] = 0;
  using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.emplace(0, s, -1);
  while (pq.size()) {
    Weight d;
    int v, u;
    tie(d, v, u) = pq.top();
    pq.pop();
    if (dist[v] < d)
      continue;
    color[v] = BLACK;
    prev[v] = u;
    for (auto &e : g[v]) {
      if (color[e.d] == BLACK)
        continue;
      if (dist[e.d] > dist[v] + e.w) {
        dist[e.d] = dist[v] + e.w;
        pq.emplace(dist[e.d], e.d, v);
        color[e.d] = GRAY;
      }
    }
  }
  return prev;
};
class Solution {
public:
  int shortestBridge(vector<vector<int>> &A) {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    auto inrange = [&](int x, int y) {
      return 0 <= x and x < A.size() and 0 <= y and y < A.size();
    };
    auto idx = [&](int x, int y) { return x * A.size() + y; };
    int s = 0;
    Graph g(A.size() * A.size());
    rep(i, 0, A.size()) rep(j, 0, A.size()) {
      if (A[i][j] == 1)
        s = idx(i, j);
      rep(k, 0, 4) {
        int x = i + dx[k], y = j + dy[k];
        if (inrange(x, y)) {
          addArc(g, idx(i, j), idx(x, y), (A[i][j] == 0 or A[x][y] == 0));
        }
      }
    }
    vector<int> dist(g.size(), INF);
    dijkstra(g, s, dist);
    dump(dist);
    int ans = INF;
    rep(i, 0, A.size()) rep(j, 0, A.size()) {
      if (dist[idx(i, j)] > 0 and A[i][j] == 1)
        chmin(ans, dist[idx(i, j)]);
    }
    return ans - 1;
  }
};
signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(N));
  rep(i, 0, N) rep(j, 0, N) { cin >> v[i][j]; }

  dump(Solution().shortestBridge(v));

  return 0;
}
