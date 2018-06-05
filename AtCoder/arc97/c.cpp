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
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
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

  string s;
  cin >> s;
  int K;
  cin >> K;
  string t(s);
  sort(all(t));
  t.erase(unique(all(t)), t.end());
  set<string> v;
  for (char c = 'a'; c <= 'z'; c++) {
    if (v.size() >= K) {
      break;
    }
    rep(i, 0, s.size()) {
      if (s[i] == c) {
        int j = i;
        string tmp;
        int cnt=0;
        while (j < s.size() and cnt++<5) {
          tmp.push_back(s[j++]);
          v.insert(tmp);
        }
      }
    }
  }
  auto it = v.begin();
  loop(K - 1) it = next(it);
  cout << *it << endl;

  return 0;
}
