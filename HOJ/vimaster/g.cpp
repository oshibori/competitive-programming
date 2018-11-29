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
istream &operator>>(istream &is, pair<T, S> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
  os << p.first << " " << p.second;
  return os;
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
template <typename T> struct BinaryIndexedTree {
  // 1-indexed
  int n;
  vector<T> d;
  // d[x] が管理する区間の長さは，x の最も下の立っているビット(x&-x)
  BinaryIndexedTree(int m) : n(m) {
    // 0 以外の値で初期化をするとき
    // ・add を 𝑁 回呼び出せば 𝑂(𝑁 log 𝑁)
    // ・𝑣𝑥 = 1 で初期化するなら bit[x] = x & -x; (x&-x は区間の長さ)
    // ・一般には bit[x] を 𝑣𝑥 で初期化したのち
    //   for (int x = 1; x < N; ++x) bit[x + (x & -x)] += bit[x];
    d.assign(m + 1, 0);
  }
  // [a,b] 1-indexed
  T sum(int a, int b) { return sum(b) - sum(a - 1); }
  T sum(int i) {
    // iから0にiの最も下の立っているbitを使って到達する最短距離
    // 次に足すべき区間は，番号から区間の長さを引くと求まる
    T ret(0);
    for (int j = i; j > 0; j -= j & (-j))
      ret += d[j];
    return ret;
  }
  void add(int i, T x) {
    // iからnにiの最も下の立っているbitを使って到達する最短距離
    // 次に更新すべき区間は，番号に区間の長さを足すと求まる
    for (int j = i; j <= n; j += j & (-j))
      d[j] += x;
  }
  // [1,n]
  int lower_bound(T w) {
    // 二分木の分かれ方に従って二分探索する
    // 左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
    // (index/2)
    // ちょうど BIT がもっている情報，𝑂(1) 時間で得られる
    //
    if (w <= 0)
      return 0;
    int x(0), y;
    for (y = 1; 2 * y <= n; y <<= 1)
      ;
    for (int k = y; k > 0; k >>= 1) {
      if (x + k <= n && d[x + k] < w) {
        w -= d[x + k];
        x += k;
      }
    }
    return x + 1;
  }
};

signed main(signed argc, char *argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<int> p(M);
  rep(i, 0, M) { cin >> p[i]; }
  BinaryIndexedTree<int> bit(N);
  rep(i, 1, N + 1) bit.add(i, 1);
  rep(i, 0, M) { bit.add(bit.lower_bound(p[i]), -1); }
  vector<int> ans;
  rep(i, 1, N + 1) {
    if (bit.sum(i, i))
      ans.eb(i);
  }

  rep(i, 0, ans.size()) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
