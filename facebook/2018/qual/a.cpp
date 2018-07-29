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

  int T;
  cin >> T;
  loop(T) {
    int N, K, V;
    cin >> N >> K >> V;
    V--;
    vector<string> a(N);
    rep(i, 0, N) { cin >> a[i]; }
    vector<pair<int, int>> d(N);
    rep(i, 0, N) { d[i] = make_pair(V*K / N, i); }
    rep(i, 0, (V*K) % N) { d[i].first++; }
    sort(all(d));
    dump(d);
    string ans = "Case #" + to_string(loop+1) + ":";
    rep(i, 0, K) { ans += " " + a[d[i].second]; }
    cout << ans << endl;
  }

  return 0;
}
