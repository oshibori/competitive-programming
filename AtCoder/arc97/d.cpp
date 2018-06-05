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
vector<vector<int>> vec;
int n;
vector<int> color;
vector<set<int>> color_inv;
void bsf(int s, int c) {
  queue<int> q;
  q.push(s);
  color[s] = c;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    rep(v, 0, vec[u].size()) {
      if (color[vec[u][v]] != -1)
        continue;
      color[vec[u][v]] = c;
      q.push(vec[u][v]);
    }
  }
}
int assignColor() {
  // O(|V|+|E|)
  int cnt = 0;
  rep(i, 0, n) {
    if (color[i] == -1) {
      bsf(i, cnt);
      cnt++;
    }
  }
  return cnt;
}

int and_set(set<int> a, set<int> b) {
  int ret = 0;
  for (auto x : a) {
    if (b.count(x))
      ret++;
  }
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vec.resize(N);
  color.resize(N, -1);
  n = N;

  vector<int> p(N);
  rep(i, 0, N) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> x(M), y(M);
  rep(i, 0, M) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;

    vec[x[i]].push_back(y[i]);
    vec[y[i]].push_back(x[i]);
  }

  int cnt = assignColor();
  dump(cnt);

  color_inv.resize(cnt,set<int>());
  vector<set<int>> st(cnt,set<int>());
  dump(color);

  rep(i, 0, N) {
    dump(i,color[i]);

    color_inv[color[i]].insert(i);
    st[color[i]].insert(p[i]);
  }
  dump(color,color_inv,st);
  int ans = 0;

  rep(i, 0, cnt) { ans += and_set(color_inv[i], st[i]); }

  cout << ans << endl;
  return 0;
}
