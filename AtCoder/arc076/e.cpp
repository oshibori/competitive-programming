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

  int R, C, N; cin >> R >> C >> N;
  stack<int>st;
  vector<vector<pii>>v(4);
  auto f=[&](int x,int y){
    return (x==0 or x==R) or (y==0 or y==C);
  };
  rep(i,0,N){
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(f(a,b)and f(c,d)){
      if(a==0)v[0].emplace_back(b,i);
      else if(b==C)v[1].emplace_back(a,i);
      else if(a==R)v[2].emplace_back(b,i);
      else v[3].emplace_back(a,i);

      if(c==0)v[0].emplace_back(d,i);
      else if(d==C)v[1].emplace_back(c,i);
      else if(c==R)v[2].emplace_back(d,i);
      else v[3].emplace_back(c,i);
    }
  }
  rep(i,0,4)sort(all(v[i]));
  reverse(all(v[2]));
  reverse(all(v[3]));

  rep(i,1,4)v[0].insert(v[0].end(),all(v[i]));

  rep(i,0,v[0].size()){
    if(st.empty())st.push(v[0][i].se);
    else if(st.top()==v[0][i].se)st.pop();
    else st.push(v[0][i].se);
  }

  YES(st.empty());



    return 0;
}
