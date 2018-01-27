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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(N));
  vector<int> c(N, 0), r(N, 0);
  rep(i, 0, N) rep(j, 0, N) {
    cin >> v[i][j];
    if (v[i][j]) {
      c[j]++;
      r[i]++;
    }
  }

  rep(i, 0, N) {
    if (r[i] == 0 or c[i] == 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  auto f = [&](vector<int> &a, vector<int> &b) {
    rep(i, 0, N) {
      if (a[i] == b[i])
        continue;
      return a[i] > b[i];
    }
    return true;
  };
//  sort(all(v), f);

  rep(i, 0, N) {
    vector<pair<vector<int>, int>> w;
    rep(j, i, N) {
      if (v[j][i]) {
        w.push_back(make_pair(v[j], j));
      }
    }
    sort(all(w), [&](pair<vector<int>, int> &a, pair<vector<int>, int> &b) {
      return f(a.first, b.first);
    });

    if (w[0].second != i) {
      swap(v[i], v[w[0].second]);
      cout << "R " << i + 1 << " " << w[0].second+1 << endl;
    }
  }
  return 0;
}
