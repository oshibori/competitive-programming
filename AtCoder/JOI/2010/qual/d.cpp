#define _GLIBCXX_DEBUG
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
void dfs(int x, int k, vector<string> &a, set<string> &s, vector<string> &v) {
  if (k == 0) {
    dump(a);
    vector<int> p(a.size());
    rep(i, 0, a.size()) p[i] = i;
    do {
      string t;
      rep(i, 0, p.size()) t += a[p[i]];
      s.insert(t);
    } while (next_permutation(all(p)));
    return;
  }
  if (x >= v.size())
    return;
   else {
    rep(i, x, v.size()) {
      a.push_back(v[i]);
      dfs(i + 1, k - 1, a, s, v);
      a.pop_back();
    }
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  set<string> s;
  vector<string> a;
  dfs(0, K, a, s, v);
  cout << s.size() << endl;

  return 0;
}
