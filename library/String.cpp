#include <bits/stdc++.h>
using namespace std;
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

// Manacher O(|S|)
//戻り値: r[i]: s[i]を中心とする最長の回文の半径 (全長+1)/2
//奇数長のみ 偶数長はダミー文字列を入れる
// http://snuke.hatenablog.com/entry/2014/12/02/235837
vector<int> manacher(const string &s) {
  int n = s.size();
  vector<int> r(n);
  int i = 0, j = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
      ++j;
    r[i] = j;
    int k = 1;
    while (i - k >= 0 && i + k < n && k + r[i - k] < j)
      r[i + k] = r[i - k], ++k;
    i += k;
    j -= k;
  }
  return r;
}

// Z algorithm O(S)
//最長共通接辞
// http://snuke.hatenablog.com/entry/2014/12/03/214243
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

signed main(void) {
  string a = "abracadabra";
  SuffixArray x(a);
  LongestCommonPrefixArray y(x);
  y.output();
  auto z = ZAlgorithm::construct(a);

  return 0;
}
