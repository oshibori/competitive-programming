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

map<char, int> &operator+=(map<char, int> &x, map<char, int> &y) {
  for (auto &o : y) {
    x[o.first] += o.second;
  }
  return x;
}
map<char,int> operator-(map<char,int>&x,map<char,int>&y){
  map<char,int>ret;
  for(auto &o:x){
    ret[o.first]=o.second-y[o.first];
  }
  return ret;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }

  vector<map<char, int>> cnt(N);
  rep(i, 0, N) {
    rep(j, 0, M) { cnt[i][v[i][j]]++; }
  }

  rep(i, 1, N) cnt[i] += cnt[i - 1];

  int ans(INF);
  rep(i,0,N-2)rep(j,i+1,N-1){
    auto x=cnt[i],y=cnt[j]-cnt[i],z=cnt[N-1]-cnt[j];

    chmin(ans,x['R']+x['B']+y['W']+y['R']+z['B']+z['W']);

  }
  cout<<ans<<endl;
  /*
      int ans(0);
  rep(i, 0, M) {
    if (v[0][i] != 'W') {
      v[0][i] = 'W';
      ans++;
    }
    if (v[N - 1][i] != 'R') {
      v[N - 1][i] = 'R';
      ans++;
    }
  }

  pair<int, int> b;
  b.first = INF, b.second = -1;
  vector<map<char, int>> x(N);
  rep(i, 1, N - 1) {
    vector<map<char, int>>::iterator cnt = x.begin() + i;
    rep(j, 0, M)(*cnt)[v[i][j]]++;
    if ((*cnt)['R'] + (*cnt)['W'] < b.first) {
      b.first = (*cnt)['R'] + (*cnt)['W'];
      b.second = i;
    }
  }

  ans += b.first;

  rep(i, 1, N - 1) {
    if (i < b.second) {

    } else if (i == b.second) {
      continue;
    } else {
    }
  }
  */

  return 0;
}
