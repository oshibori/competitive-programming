#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
int modpow(int base, int exp, int mod = MOD) {
  int ret = 1;
  while (exp) {
    if (exp & 1) {
      (ret *= base) %= mod;
    }
    (base*=base)%=mod ;
    exp >>= 1;
  }
  return ret;
}
int inv(int x, int mod = MOD) { return modpow(x, mod - 2); }
int nHr(int n, int r, int mod = MOD) {
  dump(n,r);
  if (r == 0)
    return 1;
  else {
    n += r - 1;
    dump(n,r);
    int m = min(r, n - r);
    dump(m);
    int numerator = 1, denominator = 1;
    rep(i, 0, m) {
      (numerator *= n - i) %= mod;
      (denominator *= i + 1) %= mod;
    }
    dump(numerator,denominator);
    dump(inv(1));
    return (numerator * inv(denominator)) % mod;
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  int l = 0, r = 1;
  int ans = 1;
  while (r < N) {
    while (A[r] == -1) {
      r++;
    }
    (ans *= nHr(r - l, A[r] - A[l])) %= MOD;
    l = r;
    r++;
  }
  cout << ans << endl;

  return 0;
}
