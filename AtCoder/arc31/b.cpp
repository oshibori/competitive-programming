#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
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
using P = pair<int, int>;
int sum = 0;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool inrange(int x, int y) { return 0 <= x and x < 10 and 0 <= y and y < 10; }
bool check(vector<string> v, int x, int y) {
  queue<P> q;
  int cnt = 0;
  q.push(P(x, y));
  while (q.size()) {
    P u = q.front();
    q.pop();
    if (v[u.first][u.second] == 'x')
      continue;
    v[u.first][u.second] = 'x';
    cnt++;
    rep(i, 0, 4) {
      int a = u.first + dx[i], b = u.second + dy[i];
      if (inrange(a, b) and v[a][b] == 'o') {
        q.push(P(a, b));
      }
    }
  }
  return cnt == sum+1;
}
bool solve(vector<string> &v) {
  rep(i, 0, v.size()) rep(j, 0, v[0].size()) {
    char x = v[i][j];
    v[i][j] = 'o';
    if (check(v, i, j))
      return true;
    v[i][j] = x;
  }
  return false;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  vector<string> v(10);
  rep(i, 0, 10) { cin >> v[i]; }
  for (auto a : v)
    for (auto b : a)
      if (b == 'o')
        sum++;
  cout << (solve(v) ? "YES" : "NO") << endl;

  return 0;
}
