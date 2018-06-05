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

  int N;
  cin >> N;
  set<char> s;
  for (auto x : "aeiouy,.") {
    s.insert(x);
  }
  map<char, int> m;
  m['b'] = m['c'] = '1';
  m['t'] = m['j'] = '3';
  m['w'] = m['d'] = '2';
  m['f'] = m['q'] = '4';
  m['v'] = m['l'] = '5';
  m['s'] = m['x'] = '6';
  m['p'] = m['m'] = '7';
  m['h'] = m['k'] = '8';
  m['g'] = m['n'] = '9';
  m['z'] = m['r'] = '0';

  auto f = [&](string g) {
    string ret;
    rep(i, 0, g.size()) {
      g[i] = tolower(g[i]);
      if (s.count(g[i]))
        continue;
      ret.push_back(m[g[i]]);
    }
    return ret;
  };
  vector<string> ans;
  loop(N) {
    string w;
    cin >> w;
    auto x = f(w);
    if (not x.empty())
      ans.push_back(x);
  }
  rep(i, 0, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  if(ans.empty())cout<<endl;

  return 0;
}
