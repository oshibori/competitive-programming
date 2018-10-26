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
// Z algorithm O(S)
//最長共通接辞
struct ZAlgorithm {
  //戻り値: a[i]: sとs[i:s.size()-1]の最長共通接頭辞の長さ
  static vector<int> construct(const string &s) {
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
    int i = 1, j = 0;
    while (i < n) {
      while (i + j < n && s[j] == s[i + j])
        ++j;
      a[i] = j;
      if (j == 0) {
        ++i;
        continue;
      }
      int k = 1;
      while (i + k < n && k + a[k] < j)
        a[i + k] = a[k], ++k;
      i += k;
      j -= k;
    }
    return a;
  }
  //戻り値: a[i]: tとs[i:s.size()-1]の最長共通接頭辞の長さ
  static vector<int> construct(const string &s, const string &t) {
    vector<int> a = construct(t + s);
    a.erase(a.begin(), a.begin() + t.size());
    int T = t.size();
    for (int &e : a)
      if (e > T)
        e = T;
    return a;
  }
  //戻り値: a[i]: tとs[i:s.size()-1]の最長共通接尾辞の長さ
  static vector<int> construct_suffix(string s, string t) {
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vector<int> a = construct(s, t);
    reverse(a.begin(), a.end());
    return a;
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

  auto aa = ZAlgorithm::construct(S);
  auto bb = ZAlgorithm::construct(T);

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
    l = aa[idx];
    chmin(l, rmax - 1);
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
    ll = bb[revidx];
    chmin(ll, umax - 1);
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
