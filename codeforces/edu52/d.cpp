#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}
/*
   typedef __int128_t Int;
   std::ostream &operator<<(std::ostream &dest, __int128_t value) {
   std::ostream::sentry s(dest);
   if (s) {
   __uint128_t tmp = value < 0 ? -value : value;
   char buffer[128];
   char *d = std::end(buffer);
   do {
   --d;
 *d = "0123456789"[tmp % 10];
 tmp /= 10;
 } while (tmp != 0);
 if (value < 0) {
 --d;
 *d = '-';
 }
 int len = std::end(buffer) - d;
 if (dest.rdbuf()->sputn(d, len) != len) {
 dest.setstate(std::ios_base::badbit);
 }
 }
 return dest;
 }

 __int128 parse(string &s) {
 __int128 ret = 0;
 for (int i = 0; i < s.length(); i++)
 if ('0' <= s[i] && s[i] <= '9')
 ret = 10 * ret + s[i] - '0';
 return ret;
 }
 */

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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

  int N;
  cin >> N;
  vector<pii> v(N * N);
  vector<vector<int>> A(N, vector<int>(N));
  rep(i, 0, N) rep(j, 0, N) {
    cin >> A[i][j];
    A[i][j]--;
    v[A[i][j]] = pii(i, j);
  }

  vector<vector<int>> knight(N * N, vector<int>(N * N, INF)), bishop(knight),
      rook(knight);
  auto inrange = [&](int x, int y) {
    return 0 <= x and x < N and 0 <= y and y < N;
  };

  {
    int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
    rep(i, 0, N * N) {
      knight[i][i] = 0;
      auto p = v[i];
      rep(j, 0, 8) {
        int x = p.fi + dx[j], y = p.se + dy[j];
        if (inrange(x, y)) {
          knight[i][A[x][y]] = 1;
        }
      }
    }

    rep(k, 0, N * N) rep(i, 0, N * N) rep(j, 0, N * N) {
      chmin(knight[i][j], knight[i][k] + knight[k][j]);
    }
  }

  {
    int dx[] = {1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1};
    rep(i, 0, N * N) {
      bishop[i][i] = 0;
      auto p = v[i];
      rep(j, 0, 4) {
        rep(k, 1, N + 1) {
          int x = p.fi + dx[j] * k, y = p.se + dy[j] * k;
          if (inrange(x, y)) {
            bishop[i][A[x][y]] = 1;
          }
        }
      }
    }
    rep(k, 0, N * N) rep(i, 0, N * N) rep(j, 0, N * N) {
      chmin(bishop[i][j], bishop[i][k] + bishop[k][j]);
    }
  }

  {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    rep(i, 0, N * N) {
      rook[i][i] = 0;
      auto p = v[i];
      rep(j, 0, 4) {
        rep(k, 1, N + 1) {
          int x = p.fi + dx[j] * k, y = p.se + dy[j] * k;
          if (inrange(x, y)) {
            rook[i][A[x][y]] = 1;
          }
        }
      }
    }
    rep(k, 0, N * N) rep(i, 0, N * N) rep(j, 0, N * N) {
      chmin(rook[i][j], rook[i][k] + rook[k][j]);
    }
  }

  vector<vector<pii>> dp(N * N, vector<pii>(3, pii(INF, INF)));
  vector<vector<vector<int>>> d(3);
  d[0] = knight;
  d[1] = bishop;
  d[2] = rook;

  dp[0][0] = pii(0, 0);
  dp[0][1] = pii(0, 0);
  dp[0][2] = pii(0, 0);
  rep(i, 0, N * N - 1) {
    rep(j, 0, 3) {
      rep(k, 0, 3) {
        int x = dp[i][j].fi, y = dp[i][j].se;
        dump(i, j, dp[i][j], "=> ", k, d[k][i][i + 1]);
        chmin(dp[i + 1][k], pii(x + d[k][i][i + 1] + (j != k), y + (j != k)));
      }
    }
  }

  auto p = *min_element(all(dp[N * N - 1]));
  cout << p << endl;

  return 0;
}
