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
// https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_g
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  rep(i, 0, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<vector<int>> g(N, vector<int>(N));
  rep(i, 0, M) { g[a[i]][b[i]] = g[b[i]][a[i]] = 1; }

  int n1 = N / 2, n2 = N - n1;

  vector<int> ok1(1 << n1, 1), ok2(1 << n2, 1);
  rep(i, 0, n1) rep(j, i + 1, n1) {
    if (g[i][j] == 1) {
      ok1[(1 << i) | (1 << j)] = 0;
    }
  }
  rep(i, 0, n2) rep(j, i + 1, n2) {
    int x = i + n1, y = j + n1;
    if (g[x][y] == 1) {
      ok2[(1 << i) | (1 << j)] = 0;
    }
  }
  rep(bits, 0, 1 << n1) {
    if (ok1[bits] == 0) {
      rep(i, 0, n1) { ok1[bits | (1 << i)] = 0; }
    }
  }
  rep(bits, 0, 1 << n2) {
    if (ok2[bits] == 0) {
      rep(i, 0, n2) { ok2[bits | (1 << i)] = 0; }
    }
  }

  vector<int> oset(1 << n1);
  oset[0] = (1 << n2) - 1;
  rep(i, 0, n1) {
    rep(j, 0, n2) {
      int x = n1 + j;
      if (g[i][x] == 0) {
        oset[(1 << i)] |= (1 << j);
      }
    }
  }
  rep(bits, 0, 1 << n1) {
    rep(i, 0, n1) {
      if (((bits >> i) & 1) == 0) {
        oset[bits | (1 << i)] = oset[bits] & oset[(1 << i)];
      }
    }
  }

  auto bitcount = [](int a) {
    int ret = 0;
    while (a) {
      a ^= (a & -a);
      ret++;
    }
    return ret;
  };

  vector<int> dp(1 << n2);
  rep(bits, 0, 1 << n2) {
    if (ok2[bits])
      dp[bits] = bitcount(bits);
    else
      dp[bits] = 0;

    rep(i, 0, n2) {
      if ((bits >> i) & 1 == 1)
        chmax(dp[bits], dp[bits ^ (1 << i)]);
    }
  }

  int ans = 0;
  rep(bits, 0, 1 << n1) {
    if (ok1[bits]) {
      chmax(ans, bitcount(bits) + dp[oset[bits]]);
    }
  }
  cout << ans << endl;
  return 0;
}
