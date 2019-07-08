#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
// typedef __int128_t Int;
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
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

// need
#include <algorithm>
#include <iostream>

// data structure
#include <bitset>
#include <complex>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
//#include <deque>
#include <valarray>

// stream
//#include <istream>
//#include <sstream>
//#include <ostream>
#include <fstream>

// etc
#include <cassert>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <random>

// input
#define INIT                                                                   \
  std::ios::sync_with_stdio(false);                                            \
  std::cin.tie(0);
#define VAR(type, ...)                                                         \
  type __VA_ARGS__;                                                            \
  MACRO_VAR_Scan(__VA_ARGS__);
template <typename T> void MACRO_VAR_Scan(T &t) { std::cin >> t; }
template <typename First, typename... Rest>
void MACRO_VAR_Scan(First &first, Rest &... rest) {
  std::cin >> first;
  MACRO_VAR_Scan(rest...);
}
#define VEC_ROW(type, n, ...)                                                  \
  std::vector<type> __VA_ARGS__;                                               \
  MACRO_VEC_ROW_Init(n, __VA_ARGS__);                                          \
  for (int i = 0; i < n; ++i) {                                                \
    MACRO_VEC_ROW_Scan(i, __VA_ARGS__);                                        \
  }
template <typename T> void MACRO_VEC_ROW_Init(int n, T &t) { t.resize(n); }
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Init(int n, First &first, Rest &... rest) {
  first.resize(n);
  MACRO_VEC_ROW_Init(n, rest...);
}
template <typename T> void MACRO_VEC_ROW_Scan(int p, T &t) { std::cin >> t[p]; }
template <typename First, typename... Rest>
void MACRO_VEC_ROW_Scan(int p, First &first, Rest &... rest) {
  std::cin >> first[p];
  MACRO_VEC_ROW_Scan(p, rest...);
}
#define VEC(type, c, n)                                                        \
  std::vector<type> c(n);                                                      \
  for (auto &i : c)                                                            \
    std::cin >> i;
#define MAT(type, c, m, n)                                                     \
  std::vector<std::vector<type>> c(m, std::vector<type>(n));                   \
  for (auto &r : c)                                                            \
    for (auto &i : r)                                                          \
      std::cin >> i;

// output
#define OUT(d) std::cout << (d);
#define FOUT(n, d) std::cout << std::fixed << std::setprecision(n) << (d);
#define SOUT(n, c, d) std::cout << std::setw(n) << std::setfill(c) << (d);
#define SP std::cout << " ";
#define TAB std::cout << "\t";
#define BR std::cout << "\n";
#define SPBR(i, n) std::cout << (i + 1 == n ? '\n' : ' ');
#define ENDL std::cout << std::endl;
#define FLUSH std::cout << std::flush;
#define SHOW(d)                                                                \
  { std::cerr << #d << "\t:" << (d) << "\n"; }
#define SHOWVECTOR(v)                                                          \
  {                                                                            \
    std::cerr << #v << "\t:";                                                  \
    for (const auto &xxx : v) {                                                \
      std::cerr << xxx << " ";                                                 \
    }                                                                          \
    std::cerr << "\n";                                                         \
  }
#define SHOWVECTOR2(v)                                                         \
  {                                                                            \
    std::cerr << #v << "\t:\n";                                                \
    for (const auto &xxx : v) {                                                \
      for (const auto &yyy : xxx) {                                            \
        std::cerr << yyy << " ";                                               \
      }                                                                        \
      std::cerr << "\n";                                                       \
    }                                                                          \
  }
#define SHOWQUEUE(a)                                                           \
  {                                                                            \
    auto tmp(a);                                                               \
    std::cerr << #a << "\t:";                                                  \
    while (!tmp.empty()) {                                                     \
      std::cerr << tmp.front() << " ";                                         \
      tmp.pop();                                                               \
    }                                                                          \
    std::cerr << "\n";                                                         \
  }

// utility
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define RREP(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define FORLL(i, a, b) for (ll i = ll(a); i < ll(b); ++i)
#define RFORLL(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)
#define REPLL(i, n) for (ll i = 0; i < ll(n); ++i)
#define RREPLL(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define IN(a, x, b) (a <= x && x < b)
template <typename T> inline T CHMAX(T &a, const T b) {
  return a = (a < b) ? b : a;
}
template <typename T> inline T CHMIN(T &a, const T b) {
  return a = (a > b) ? b : a;
}
#define EXCEPTION(msg)                                                         \
  throw std::string("Exception : " msg " [ in ") + __func__ + " : " +          \
      std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg)                                                         \
  try {                                                                        \
    if (cond)                                                                  \
      EXCEPTION(msg);                                                          \
  } catch (std::string s) {                                                    \
    std::cerr << s << std::endl;                                               \
  }
void CHECKTIME(std::function<void()> f) {
  auto start = std::chrono::system_clock::now();
  f();
  auto end = std::chrono::system_clock::now();
  auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start))
                 .count();
  std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n";
}

// test
template <class T> std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
template <typename S, typename T>
std::ostream &operator<<(std::ostream &os, std::pair<S, T> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename S, typename T>
std::ostream &operator<<(std::ostream &os, std::map<S, T> p) {
  os << "{";
  for (auto x : p) {
    os << x << ", ";
  }
  os << "}";
}

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;                         // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;             // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                         // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62); // 9.22x10^18
constexpr double EPS = 1e-9;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

template <class T, size_t N> void FILL(T (&a)[N], const T &val) {
  for (auto &x : a)
    x = val;
}
template <class ARY, size_t N, size_t M, class T>
void FILL(ARY (&a)[N][M], const T &val) {
  for (auto &b : a)
    FILL(b, val);
}
template <class T> void FILL(std::vector<T> &a, const T &val) {
  for (auto &x : a)
    x = val;
}
template <class ARY, class T>
void FILL(std::vector<std::vector<ARY>> &a, const T &val) {
  for (auto &b : a)
    FILL(b, val);
}

// ------------>8------------------------------------->8------------

signed main() {
  INIT;

  VAR(std::string, s);
  int n = s.size();

  std::map<int, std::vector<int>> mp;

  int now = 0;
  mp[now].emplace_back(-1);
  REP(i, n) {
    now += (s[i] == '(' ? 1 : -1);
    mp[now].emplace_back(i);
  }

  for (auto x : mp) {
    dump(x.first, x.second);
  }

  int ans = 0;
  std::set<int> set;
  set.insert(INFINT);
  for (auto &p : mp) {
    auto &v = p.second;
    int cnt = 1;
    dump(p.first,v);
    REP(i, v.size()) {
      auto t = *set.lower_bound(v[i]);
      dump(i, t);
      if (i + 1 == v.size() || t < v[i + 1]) {
        ans += (cnt - 1) * cnt / 2;
        cnt = 1;
      } else
        ++cnt;
      dump(cnt);
    }
    REP(i, v.size()) set.insert(v[i]);
    dump(set);
  }
  OUT(ans) BR;
  return 0;
}