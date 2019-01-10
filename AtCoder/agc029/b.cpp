#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
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
class MaximumMatching {
  /*
  Maximum Matching in General Graphs
  - O(nm \log_{\max\{2, 1 + m/n\}} n) time
  - O(n + m) space
  Note: each vertex is 1-indexed.
  */

public:
  struct Edge {
    int from, to;
  };

  MaximumMatching(int N, const vector<Edge> &raw_edges) : N(N) {
    ofs.assign(N + 2, 0);
    for (auto &e : raw_edges)
      ++ofs[e.from + 1], ++ofs[e.to + 1];
    for (int i = 1; i <= N + 1; ++i)
      ofs[i] += ofs[i - 1];
    edges.resize(2 * raw_edges.size());
    for (auto &e : raw_edges) {
      edges[ofs[e.from]++] = {e.from, e.to};
      edges[ofs[e.to]++] = {e.to, e.from};
    }
    for (int i = N + 1; i > 0; --i)
      ofs[i] = ofs[i - 1];
    ofs[0] = 0;
  }

  int maximum_matching() {
    vector<int> label(N + 1, -1), mate(N + 1, 0), first(N + 1, 0);
    vector<int> que(N);
    int qh = 0, qt = 0;

    auto enqueue = [&](int v) { que[qt++] = v; };
    auto dequeue = [&] { return que[qh++]; };
    auto encode = [&](int eid) { return (N + 1) + eid; };
    auto decode = [&](int h) { return h - (N + 1); };

    function<int(int)> find_first = [&](int v) {
      return label[first[v]] < 0 ? first[v] : first[v] = find_first(first[v]);
    };

    function<void(int, int)> rematch = [&](int v, int w) {
      auto t = mate[v];
      mate[v] = w;
      if (mate[t] != v)
        return;
      if (label[v] <= N) {
        mate[t] = label[v];
        rematch(label[v], t);
      } else {
        auto &e = edges[decode(label[v])];
        int x = e.from, y = e.to;
        rematch(x, y);
        rematch(y, x);
      }
    };

    auto contract = [&](int x, int y, int eid) {
      int r = find_first(x), s = find_first(y);
      if (r == s)
        return;
      auto h = encode(eid);
      label[r] = label[s] = -h;
      int join = -1; // mate[lca]
      while (1) {
        if (s != 0)
          swap(r, s);
        r = find_first(label[mate[r]]);
        if (label[r] == -h) {
          join = r;
          break;
        } else
          label[r] = -h;
      }
      for (auto v : {first[x], first[y]}) {
        for (; v != join; v = first[label[mate[v]]]) {
          label[v] = h;
          first[v] = join;
          enqueue(v);
        }
      }
    };

    auto augmented = [&](int u) {
      label[u] = first[u] = 0;
      for (qh = qt = 0, enqueue(u); qh < qt;) {
        auto x = dequeue();
        for (int eid = ofs[x]; eid < ofs[x + 1]; ++eid) {
          auto y = edges[eid].to;
          if (mate[y] == 0 && y != u) {
            mate[y] = x;
            rematch(x, y);
            return true;
          } else if (label[y] >= 0) {
            contract(x, y, eid);
          } else if (label[mate[y]] < 0) {
            label[mate[y]] = x;
            first[mate[y]] = y;
            enqueue(mate[y]);
          }
        }
      }
      return false;
    };

    int match = 0;
    for (int u = 1; u <= N; ++u)
      if (mate[u] == 0 && augmented(u)) {
        match += 1;
        if (N - 2 * match <= 1)
          break;
        if (10 * qt < N) {
          label[0] = -1;
          for (int qi = 0; qi < qt; ++qi) {
            label[que[qi]] = label[mate[que[qi]]] = -1;
          }
        } else
          fill(label.begin(), label.end(), -1);
      }

    /*
    vector< pair<int, int> > matching(match);
    match = 0;
    rep(u, 1, N + 1) if (mate[u] > u) {
      matching[match++] = {u, mate[u]};
    }
    */

    return match;
  }

private:
  int N;
  vector<int> ofs;
  vector<Edge> edges;
};

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);
  using Edge = MaximumMatching::Edge;

  int N;
  cin >> N;
  map<int, vector<int>> mp;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A[i];
    mp[A[i]].eb(i);
  }
  vector<Edge> edges;

  rep(i, 0, N) {
    rep(j, 1, 31) {
      int x = (1ll << j) - A[i];
      if (mp.count(x)) {
        for (int k : mp[x]) {
          if (i < k) {
            Edge e = {i + 1, k + 1};
            edges.eb(e);
          }
        }
      }
    }
  }

  auto mm = MaximumMatching(N, edges);
  cout << mm.maximum_matching()+ans << endl;

  return 0;
}
