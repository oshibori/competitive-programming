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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int H, W;
  cin >> H >> W;
  vector<string> v(H);
  rep(i, 0, H) { cin >> v[i]; }

  map<char, vector<map<char, int>>> vv;

  rep(i, 0, H) rep(j, 0, W) {
    map<char, int> t;
    t[v[i][j]]++;
    rep(k, 0, H) {
      if (k == i)
        continue;
      t[v[k][j]]++;
    }
    rep(k, 0, W) {
      if (k == j)
        continue;
      t[v[i][k]]++;
    }
    vv[v[i][j]].push_back(t);
  }

  bool f = true;
  int c=0;
  for (auto x : vv) {
    auto y = x.second;

    int n = y.size();
    vector<bool> used(n, false);
    rep(i, 0, n) {
      if(used[i])continue;
      rep(j, i + 1, n) {
        if (used[j])
          continue;
        if (y[i] == y[j]) {
          used[j] = true;
          break;
        }

        if (j == n - 1) {
          f = false;
          c++;
        }
      }
    }
  }

  if(H%2==1 and W%2==1 and c==1)f=true;
  cout << (f ? "YES" : "NO") << endl;
  return 0;
}
