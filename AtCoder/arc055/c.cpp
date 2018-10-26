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
struct LongestCommonPrefixArray {
  const SuffixArray &SA;
  vector<int> rank, lcp;
  LongestCommonPrefixArray(const SuffixArray &SA) : SA(SA), lcp(SA.size()) {
    rank.resize(SA.size());
    for (int i = 0; i < SA.size(); i++) {
      rank[SA[i]] = i;
    }
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < SA.S.length(); i++) {
      if (h > 0)
        h--;
      for (int j = SA[rank[i] - 1];
           j + h < SA.S.length() and i + h < SA.S.length(); h++) {
        if (SA.S[i + h] != SA.S[j + h])
          break;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  int operator[](int k) { return lcp[k]; }
  int operator[](int k) const { return lcp[k]; }
  // |S|+1
  size_t size() const { return lcp.size(); }
  void output() {
    cerr << "S = " << SA.S << ", |S| = " << SA.S.length() << endl;
    cerr << "rank : SA, lcp" << endl;
    for (int i = 0; i < size(); i++) {
      cerr << setw(3) << i << " : " << setw(3) << SA[i] << " " << setw(3)
           << lcp[i] << " " << SA.S.substr(SA[i]) << endl;
    }
  }
};
struct Bucket {
  vector<int> v;
  vector<int> mini;
  int s;
  Bucket(vector<int> w) : v(w) {
    s = sqrt(v.size());
    mini.resize((v.size() + s - 1) / s, INF);
    rep(i, 0, v.size()) { chmin(mini[i / s], v[i]); }
  }
  // [l,r)
  int rmq(int l, int r) {
    int ret = INF;
    while (l < r and l % s != 0) {
      chmin(ret, v[l++]);
    }
    while (l < r and r % s != 0) {
      chmin(ret, v[--r]);
    }
    while (l < r) {
      chmin(ret, mini[l / s]);
      l += s;
    }
    return ret;
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
  SuffixArray aa(S);
  LongestCommonPrefixArray bb(aa);
  //  bb.output();
  Bucket cc(bb.lcp);
  SuffixArray dd(T);
  LongestCommonPrefixArray ee(dd);
  Bucket ff(ee.lcp);
  // ee.output();

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
    int l =
        cc.rmq(min(bb.rank[0], bb.rank[idx]), max(bb.rank[0], bb.rank[idx]));
    dump(l);
    chmin(l, rmax - 1);
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
    int ll = ff.rmq(min(ee.rank[0], ee.rank[revidx]),
                    max(ee.rank[0], ee.rank[revidx]));
    dump(ll);
    chmin(ll, umax - 1);
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
