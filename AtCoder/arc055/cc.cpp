#include <bits/stdc++.h>

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
struct SuffixArray {
  //　接尾辞配列
  // doubling O(n(logn)^2)
  vector<int> rank, sa;
  // rank: index -> rank
  // sa: rank -> index
  int n, k;
  string S;
  bool compare_sa(int i, int j) {
    if (rank[i] != rank[j])
      return rank[i] < rank[j];
    else {
      int ri = i + k <= n ? rank[i + k] : -1;
      int rj = j + k <= n ? rank[j + k] : -1;
      return ri < rj;
    }
  }
  SuffixArray(string S) { construct_sa(S); }
  void construct_sa(string s) {
    S = s;
    n = S.length();
    rank.resize(n + 1);
    sa.resize(n + 1);
    vector<int> tmp(n + 1);
    for (int i = 0; i <= n; i++) {
      sa[i] = i;
      rank[i] = i < n ? S[i] : -1;
    }
    for (k = 1; k <= n; k <<= 1) {
      sort(sa.begin(), sa.end(),
           [this](int x, int y) { return compare_sa(x, y); });
      // sa[0]=n
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[sa[i]] = tmp[sa[i - 1]] + compare_sa(sa[i - 1], sa[i]);
      }
      for (int i = 0; i <= n; i++) {
        rank[i] = tmp[i];
      }
    }
  }
  bool contain(string t) {
    // sa[0]=n
    int l = 0, r = S.length(); // (l,r]
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (S.compare(sa[m], t.length(), t) < 0)
        l = m;
      else
        r = m;
    }
    return S.compare(sa[r], t.length(), t) == 0;
  }
  int operator[](int k) { return sa[k]; }
  int operator[](int k) const { return sa[k]; }
  // |S|+1
  size_t size() const { return sa.size(); }
};
// Roling Hash
// RollingHash RH(s,base) base:[2,MOD)の乱数
// RH.set(s,base): vectorを再構築するのは重いのでコンストラクタを使わない
// RH.get(l,r): [l,r)のハッシュ O(1)
// 1000000007, 1000000009, 1000000021
template <long long MOD> struct RollingHash {
  int n;
  long long base;
  vector<long long> pow, hash;
  RollingHash() {}
  RollingHash(const string &s, long long base_ = 10007) { init(s, base_); }
  void init(const string &s, long long base_ = 10007) {
    n = s.size();
    base = base_;
    calc(s.c_str());
  }
  long long get(int x) const { return hash[x]; }
  long long get(int l, int r) const {
    return (get(r) - get(l) * pow[r - l] % MOD + MOD) % MOD;
  }
  void calc(const char *s) {
    pow.resize(n + 1);
    pow[0] = 1;
    hash.resize(n + 1);
    hash[0] = 0;
    for (int i = 0; i < n; i++) {
      pow[i + 1] = pow[i] * base % MOD;
      hash[i + 1] = (s[i] + hash[i] * base) % MOD;
    }
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  string S;
  cin >> S;
  string T = S;
  reverse(all(T));
  int N = S.size();
  dump(N);
  vector<int> X;
  rep(i, 3, N - 1) {
    if (S[i - 1] == S[N - 1] and S[i] == S[0])
      X.eb(i);
  }
  dump(X);
  RollingHash<MOD> aa(S), bb(T);

  int ans = 0;
  rep(i, 0, X.size()) {
    int idx = X[i];
    int lenAC = N - idx;
    int lenB = N - 2 * lenAC;
    if (lenB < 1)
      continue;
    dump(idx, lenAC, lenB);

    int rmax = min(idx, N - idx);
    // [l,r)
    int l = 1, r = rmax;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (aa.get(0, m) == aa.get(idx, idx + m))
        l = m;
      else
        r = m;
    }
    // chmin(l, rmax - 1);
    // while (l < rmax and S[l] == S[idx + l])
    //  l++;
    /*
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (S.substr(0, m) == S.substr(idx, m))
        l = m;
      else
        r = m;
    }
    */
    // if (l == rmax)
    //  l--;

    int revidx = N - 1 - (idx - 1);
    int umax = min(revidx, N - revidx);
    int ll = 1, rr = umax;
    while (rr - ll > 1) {
      int m = (ll + rr) / 2;
      if (bb.get(0, m) == bb.get(revidx, revidx + m))
        ll = m;
      else
        rr = m;
    }
    dump(ll);
    // chmin(ll, umax - 1);
    // int ll = 0;
    // int rr = rmax + 1;
    // while (ll < umax and T[ll] == T[revidx + ll])
    //  ll++;
    /*
    while (rr - ll > 1) {
      int m = (ll + rr) / 2;
      if (T.substr(0, m) == T.substr(revidx, m))
        ll = m;
      else
        rr = m;
    }
    */
    // if (umax == ll)
    //  ll--;
    dump(max(0ll, ll + l - (N - idx) + 1));
    ans += max(0ll, ll + l - (N - idx) + 1);
  }
  cout << ans << endl;

  return 0;
}
