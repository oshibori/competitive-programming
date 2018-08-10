#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define dump(...)
#define int long long
// typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
using pii = pair<int, int>;
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
typedef pair<int, int> P;
struct State {
  int s = 0, cost = 0, value = 0;
  State() {}
  State(int s, int cost, int value) : s(s), cost(cost), value(value) {}
};
ostream &operator<<(ostream &os, State a) {
  dump(a.s, a.cost, a.value);
  return os;
}
int bitcount(int x) {
  int ret = !!x;
  while (x -= x & -x)
    ret++;
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> x(N + 1);
  rep(i, 1, N + 1) { cin >> x[i]; }
  vector<int> c(N);
  rep(i, 0, N) { cin >> c[i]; }
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  rep(i, 1, N + 1) x[i] += x[i - 1];

  vector<vector<int>> f(N + 1, vector<int>(1 << N));

  rep(k, 1, N + 1) {
    rep(bits, 1, 1 << N) {
      int cost = 0, value = 0;
      rep(i, 0, N) {
        if (bits >> i & 1) {
          cost += c[i];
          value += v[i];
        }
      }
      if (cost <= x[k]) {
        f[k][bits] = value;
      } else {
        rep(i, 0, N) {
          if (bits >> i & 1) {
            chmax(f[k][bits], f[k][bits ^ (1 << i)]);
          }
        }
      }
      dump(k, bits, f[k][bits]);
    }
  }

  vector<int> dp(1 << N);
  rep(bits, 1, 1 << N) {
    dp[bits] = f[N - bitcount(bits)][bits];
    dump(N - bitcount(bits), bits, dp[bits]);
    int x = INF;
    rep(i, 0, N) {
      if (bits >> i & 1) {
        chmin(x, dp[bits ^ (1 << i)]);
      }
    }
    chmax(dp[bits], x);
    dump(N - bitcount(bits), bits, dp[bits]);
  }

  cout << dp.back() << endl;

  dump(f);
  dump(dp);
  return 0;
}
