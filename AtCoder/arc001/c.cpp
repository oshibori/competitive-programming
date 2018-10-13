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
bool inrange(int x, int y) { return 0 <= x and x < 8 and 0 <= y and y < 8; }
string column(vector<string> v, int idx) {
  string ret;
  rep(i, 0, 8) ret += v[i][idx];
  return ret;
}
int dx[] = {0, -1, 0, 1, 1, -1, -1, 1}, dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
vector<pii> result;
bool dfs(vector<string> v) {
  int sum = 0;
  vector<vector<int>> w(8, vector<int>(8));
  rep(i, 0, 8) rep(j, 0, 8) {
    if (v[i][j] != 'Q')
      continue;

    sum++;
    w[i][j]++;
    rep(k, 0, 8) {
      int x = i + dx[k], y = j + dy[k];
      while (inrange(x, y)) {
        w[x][y]++;
        if(v[x][y]=='Q')return false;
        x += dx[k], y += dy[k];
      }
    }
  }
  if (sum == 8) {
    rep(i, 0, 8) rep(j, 0, 8) cout << v[i][j] << (j == 7 ? "\n" : "");
    return true;
  }
  vector<pii> candidate;
  rep(i, 0, 8) rep(j, 0, 8) {
    if (w[i][j] == 0)
      candidate.emplace_back(i, j);
  }

  for (auto p : candidate) {
    int x = p.fi, y = p.se;
    v[x][y] = 'Q';
    if (dfs(v)) {
      return true;
    }
    v[x][y] = '.';
  }
  return false;
}
signed main() {

  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> v(8);
  rep(i, 0, 8) { cin >> v[i]; }
  if(!dfs(v)){
    cout<<"No Answer"<<endl;
  }

  return 0;
}
