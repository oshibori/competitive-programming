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

bool contain(string a, string b) {
  if (a.size() < b.size())
    return false;

  for (int i = 0; i + b.size() <= a.size(); i++) {
    if (a.substr(i, b.size()) == b)
      return true;
  }
  return false;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;

  while (cin >> N, N) {
    vector<string> s(N), v;
    rep(i, 0, N) { cin >> s[i]; }
    rep(i, 0, N) {
      bool f = false;
      rep(j, 0, N) {
        if (i != j)
          f |= contain(s[j], s[i]);
      }
      if (not f)
        v.push_back(s[i]);
    }
    N=v.size();

    vector<vector<int>> w(N, vector<int>(N));
    rep(i, 0, N) rep(j, 0, N) {
      if (i == j)
        continue;
      string a = v[i], b = v[j];
      int m = min(a.size(), b.size());
      rep(k, 1, m + 1) {
        if (a.substr(a.size() - k) == b.substr(0, k))
          chmax(w[i][j], k);
      }
    }

    int ans = 0;
    rep(i, 0, N) {
      vector<int> used(N);
      used[i] = true;
      int j = i;
      int sum = 0;
      loop(N - 1) {
        int a = -1;
        int ind = 0;
        rep(k, 0, N) {
          if ((not used[k]) and chmax(a, w[j][k]))
            ind = k;
        }
        sum += w[j][ind];
        j = ind;
      }
      chmax(ans, sum);
    }

    int x = 0;
    rep(i, 0, N) x += v[i].size();
    cout << x - ans << endl;
  }

  return 0;
}
