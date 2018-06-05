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

  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;

  string ss(s);
  sort(all(ss));
  ss.erase(unique(all(ss)), ss.end());
  dump(ss);
  vector<int> ord(N);
  rep(i, 0, N) {
    dump(s[i]);
    ord[i] = distance(ss.begin(), lower_bound(all(ss), s[i]));
  }
  dump(ord);

  vector<int> v;
  rep(i, 0, min(N, K)) v.push_back(ord[i]);
  if (N < K) {
    loop(abs(N - K)) { v.push_back(0); }
  } else {
    v[K - 1]++;
  }

  rrep(i, 0, K) {
    if (v[i] == ss.size()) {
      if (i == 0) {
        return 1;
      }
      v[i - 1]++;
      v[i] = 0;
    }
  }

  string ans;
  rep(i, 0, K) { ans.push_back(ss[v[i]]); }
  cout << ans << endl;
  return 0;
}
