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
int gcd(int x, int y) { return (y == 0 ? x : gcd(y, x % y)); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
int dfs(vector<int> &p, vector<int> &q, vector<int> &a, vector<int> &b,
        int root) {

  if (root == 0)
    return 1;
  int l = dfs(p, q, a, b, a[root]), r = dfs(p, q, a, b, b[root]);
  int x = lcm(l * p[root], r * q[root]);
  return x / q[root] + x / p[root];
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> p(N + 1), q(N + 1), a(N + 1), b(N + 1), indeg(N + 1);
  rep(i, 1, N + 1) {
    cin >> p[i] >> q[i] >> a[i] >> b[i];
    indeg[a[i]]++, indeg[b[i]]++;
  }

  int root = find(all(indeg), 0) - indeg.begin();

  cout << dfs(p, q, a, b, root) << endl;

  return 0;
}
