#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
//#define int __int128_t
typedef __int128_t Int;
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
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T> void printvv(const vector<vector<T>> &v) {
  cerr << endl;
  rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
    if (typeid(v[i][j]) == typeid(INF) and v[i][j] == INF) {
      cerr << "INF";
    } else
      cerr << v[i][j];
    cerr << (j == v[i].size() - 1 ? '\n' : ' ');
  }
  cerr << endl;
}

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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int K;
  cin >> K;
  int N;
  cin >> N;
  vector<int> A(N), D(N);
  rep(i, 0, N) { cin >> A[i] >> D[i]; }
  int l = 0;
  auto m = max_element(all(A));
  int idx = m - A.begin();
  int r = (int)1e3 + K * (int)1e3;

  auto f = [&](int v) {
    int sm = 0, big = 0, eq = 0;
    int tmp = 0;
    rep(i, 0, N) {
      dump(i, A[i], D[i], tmp);
      if (A[i] > v) {
        big++;
        dump(big);
      } else if (v - A[i] == 0ll) {
        eq++;
        dump(eq)
      } else {
        int n = (v - A[i] + D[i] - 1ll) / D[i];
        dump(n);
        sm += n;
        tmp += (2ll * A[i] + (n - 1ll) * D[i]) * n / 2ll;
        if ((v - A[i]) % D[i] == 0ll) {
          eq++;
        }
        dump(sm, eq);
      }
    }
    dump(sm + eq >= K);
    return sm + eq >= K;

  };
  while (r - l > 1) {
    int m = (l + r) / 2;
    dump(l, r, m);
    if (f(m))
      r = m;
    else
      l = m;
  }
  dump(l, r);

  int ans = 0;
  int sm = 0, big = 0, eq = 0;
  int v = r;
  rep(i, 0, N) {
    if (A[i] > v) {
      big++;
    } else if (v - A[i] == 0ll) {
      eq++;
    } else {
      int n = (v - A[i] + D[i] - 1ll) / D[i];
      sm += n;
      int a = A[i], d = D[i];
      int two = 2, one = 1;
      ans += a * n + (n - one) * n / two * d;
      if ((v - A[i]) % D[i] == 0ll) {
        eq++;
      }
    }
  }
  int k = K, zero = 0;
//  assert(K - sm == eq);
  ans += max(zero, K - sm) * v;
  cout << ans << endl;

  return 0;
}
