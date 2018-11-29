#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
int depth[301], visited[301], tmp_visited[301];
int N, M, K;
int root;
vector<int> g[301];
void _depth(int v, int d) {
  depth[v] = d;
  for (auto x : g[v]) {
    _depth(x, d + 1);
  }
}
void visit(int v) {
  if (visited[v] == -1)
    return;
  visited[v] = 1;
  for (auto x : g[v]) {
    visit(x);
  }
}
int assume(int i, int v, int s) {
  memcpy(tmp_visited, visited, sizeof(visited));
  visited[v] = -1;
  visit(root);
  vector<int> w;
  rep(i, 0, N) {
    if (visited[i] == 1) {
      w.eb(depth[i]);
    }
  }
  memcpy(visited, tmp_visited, sizeof(visited));
  sort(all(w));
  if (w.size() < M - i) {
    return 0;
  }
  s += depth[v];
  int a = accumulate(w.begin(), w.begin() + (M - i), 0ll);
  int b = accumulate(w.end() - (M - i), w.end(), 0ll);
  if (a <= K - s and K - s <= b) {
    return 1;
  } else
    return 0;
}
void update(int v){
  visited[v]=-1;
  for(auto x:g[v]){
    update(x);
  }
}

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> M >> K;
  vector<int> p(N);
  rep(i, 0, N) {
    cin >> p[i];
    p[i]--;
    if (p[i] == -1) {
      root = i;
    } else {
      g[p[i]].eb(i);
    }
  }
  _depth(root, 1);
  vector<int> ans;
  rep(i, 0, N) { visited[i] = 0; }
  int s = 0;
  rep(i, 0, M) {
    bool f = false;
    rep(j, 0, N) {
      if (visited[j] == 0) {
        int ret = assume(i + 1, j, s);
        dump(i+1,j,s,ret);
        if (ret) {
          ans.eb(j);
          update(j);
          s += depth[j];
          f = true;
          break;
        }
      }
    }
    if (f == false) {
      cout << -1 << endl;
      exit(0);
    }
  }
  rep(i, 0, M) { cout << ans[i] + 1 << (i == M - 1 ? '\n' : ' '); }

  return 0;
}
