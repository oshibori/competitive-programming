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
template <typename T> struct RangeMinimumQuery {
  // 1-indexedで木を構成
  // それぞれの要素は 0-indexed
  int n;
  vector<T> d;
  RangeMinimumQuery(int m) {
    // m is the number of data
    // 簡単にするため、要素数を２のべき乗に
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, INF);
  }
  RangeMinimumQuery(vector<T> &v) {
    int m = v.size();
    for (n = 1; n < m; n <<= 1)
      ;
    d.assign(2 * n, INF);
    for (int i = 0; i < m; i++)
      d[n + i] = v[i];
    for (int i = (n + m - 1) / 2; i > 0; i--) {
      d[i] = min(d[i * 2], d[i * 2 + 1]);
    }
  }
  void update(int i, T x) {
    // update ith (0-indexed) number
    // index i に対応するleaf node の
    // The index of leaf node which corresponds to ith num is (n+i).
    d[n + i] = x;
    for (int j = (n + i) / 2; j > 0; j >>= 1) {
      d[j] = min(d[j * 2], d[j * 2 + 1]); // children: (2*n),(2*n+1)
      // 簡単に親や子にアクセスできる
      // This is why SegmentTree is a complete binary tree.
    }
  }
  T query(int l, int r) {
    // query [l,r)
    return query(l, r, 1, 0, n); // nでないと完全二分木にならない
  }
  T query(int a, int b, int k, int l, int r) {
    // query for min of [a,b)
    // 後ろの方の引数は、計算の簡単化のための引数
    // kは節点の番号、l,r はその節点が[l,r)に対応付いていることを表す
    // したがって、外からはquery(a,b,1,0,n)として呼ぶ

    // [a,b) と [l,r)が交差しなければINF
    if (r <= a || b <= l)
      return INF;

    // [a,b)が[l,r)を完全に含んでいれば、この節点の値
    if (a <= l && r <= b)
      return d[k];
    else {
      //そうでなければ、2つの子の最小値
      T vl = query(a, b, k * 2, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, L;
  cin >> N >> L;
  vector<tuple<int, int, int>> lrc;
  loop(N) {
    int l, r, c;
    cin >> l >> r >> c;
    lrc.eb(r, l, c);
  }
  sort(all(lrc));
  RangeMinimumQuery<int> seg(L + 1);
  seg.update(0, 0);
  rep(i, 0, N) {
    int r, l, c;
    tie(r, l, c) = lrc[i];
    dump(l, r, c);
    int x = seg.query(l, r);
    int y = seg.query(r, r + 1);
    dump(x, y);
    seg.update(r, min(x + c, y));
    dump(seg.d);
  }
  cout << seg.query(L, L + 1) << endl;
  ;

  return 0;
}
