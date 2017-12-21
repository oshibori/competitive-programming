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

int dfs(vector<int> &v, vector<int> t, int index) {
  if (index == 13) {
    vector<int> x;
    rep(i, 0, t.size()) {
      rep(j, 0, t[i]) { x.push_back(i); }
    }
    rep(i, 0, t.size()) {
      rep(j, 0, t[i]) { x.push_back(i); }
    }
    int ret(INF);
    rep(i, 0, x.size() - 1) {
      chmin(ret, min(abs(x[i] - x[i + 1]), 24 - abs(x[i] - x[i + 1])));
    }
    return ret;
  }

  if (v[index] == 0) {
    return dfs(v, t, index + 1);
  } else if (v[index] == 1) {
    t[index]++;
    int a = dfs(v, t, index + 1);
    t[index]--;
    t[(24 - index) % 24]++;
    int b = dfs(v, t, index + 1);
    return max(a, b);
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> D(N);
  rep(i, 0, N) cin >> D[i];
  vector<int> t(25, 0);
  t[0] = 1;

  vector<int> v(13, 0);
  rep(i, 0, D.size()) { v[D[i]]++; }
  rep(i, 0, v.size()) {
    if (v[i] >= 3) {
      cout << 0 << endl;
      return 0;
    }
  }
  rep(i, 0, v.size()) {
    if (v[i] == 2) {
      t[i]++;
      t[(24 - i) % 24]++;
      v[i] = 0;
    }
  }
  cout << dfs(v, t, 0) << endl;

  return 0;
}
