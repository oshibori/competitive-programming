#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
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

  string s;
  cin >> s;
  vector<int> factorial(21);
  factorial[0] = 1;
  rep(i, 1, 21) factorial[i] = factorial[i - 1] * i;
  dump(factorial);
  auto p = [&](map<char, int> m) {
    int sum = 0;
    for (auto &o : m) {
      sum += o.second;
    }
    int ret = factorial[sum];
    for (auto &o : m) {
      ret /= factorial[o.second];
    }
    return ret;
  };

  int ans = 1;
  rep(i, 0, s.size()) {
    auto t = s.substr(i);
    sort(all(t));
    t.erase(unique(all(t)), t.end());
    map<char, int> m;
    rep(j, 0, t.size()) {
      if (m.count(t[j]))
        continue;
      m[t[j]] = j;
    }
    auto x = s.substr(i);
    map<char, int> y;
    rep(j, 0, x.size()) y[x[j]]++;
    rep(j, 0, t.size()) {
      if (t[j] == s[i])
        break;
      y[t[j]]--;
      ans += p(y);
      y[t[j]]++;
    }

    dump(ans);
  }
  cout << ans << endl;

  return 0;
}
