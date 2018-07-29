#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
//typedef __int128_t Int;
#define DBG 1
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define loop(n) rep(loop,(0),(n))
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> class DisjointSet {
public:
  vector<T> rank, p;
  DisjointSet() {}
  DisjointSet(int size) {
    rank.resize(size, 0);
    p.resize(size, 0);
    rep(i, 0, size) makeSet(i);
  }
  void makeSet(int x) {
    p[x] = x;
    rank[x] = 0;
  }
  bool same(int x, int y) { return findSet(x) == findSet(y); }
  bool unite(int x, int y) {
    if (same(x, y))
      return false;
    link(findSet(x), findSet(y));
    return true;
  }
  void link(int x, int y) {
    if (rank[x] > rank[y]) {
      p[y] = x;
    } else {
      p[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
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
  cout<<fixed<<setprecision(12);

  int N, M; cin >> N >> M;
  vector<int> p(N); rep(i, 0, N){ cin >> p[i];p[i]--; }
  vector<int> x(M), y(M); rep(i, 0, M){ cin >> x[i] >> y[i];x[i]--,y[i]--; }
  DisjointSet<int>uf(N);
  rep(i,0,M){
    uf.unite(p[x[i]],p[y[i]]);
  }
  int ans=0;
  rep(i,0,N){
    ans+=uf.same(i,p[i]);
  }
  cout<<ans<<endl;

    return 0;
}
