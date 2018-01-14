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

int N, L;
int dfs(vector<int> &a, vector<int> &t, int x) {
  dump(t, x);
  if (t[x] != -1)
    return t[x];

  vector<pair<int, int>> v;
  v.push_back(make_pair(a[x], x));
  v.push_back(make_pair(a[x - 1], x - 1));
  v.push_back(make_pair(a[x + 1], x + 1));
  sort(all(v));

  if (v[2].second == x) {
    t[x] = L - a[x];
  } else if (v[1].second == x) {
    t[x] = L - a[x] + dfs(a, t, v[2].second);
  } else if (v[0].second == x) {
    t[x] = L - a[x] + max(dfs(a, t, v[1].second), dfs(a, t, v[2].second));
  }
  dump(t, x);
  return t[x];
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> L;
  vector<pair<int, int>> b(N);
  rep(i, 0, N) {
    cin >> b[i].first;
    b[i].second = i+1;
  }
  sort(all(b), greater<pair<int, int>>());
  dump(b);
  vector<int> t(N + 2, 0);
  rep(i, 0, N) {
    int x = b[i].first, y = b[i].second;
    t[y] = max(t[y - 1], t[y + 1]) + L - x;
  }
  cout<<*max_element(all(t))<<endl;

  //  vector<int> a(N + 2, 0);
  //  rep(i, 1, N + 1) { cin >> a[i]; }
  //  vector<int> t(N + 2, -1);
  //  t[0] = t[N + 1] = 0;
  //  rep(i,1,N+1)dfs(a,t,i);
  //  cout<<*max_element(all(t))<<endl;

  return 0;
}
