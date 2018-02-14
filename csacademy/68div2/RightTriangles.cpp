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
using P = pair<int, int>;
int longest_increasing_subsequence(const vector<int> &v) {
  // これまで出てきた中で、k枚の部分列が作れるもののうち、最も値が小さいものを持つ
  int n = v.size();
  vector<int> dp(n, INF);
  for (int i = 0; i < n; i++)
    *lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
  return find(dp.begin(), dp.end(), INF) - dp.begin();
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  vector<P> v(N);
  rep(i, 0, N) {
    int x, y;
    cin >> x >> y;
    v[i] = P(x, y);
  }
  vector<P> w(v);
  map<P, int> m;

  sort(all(v));
  vector<P> dp(N, P(INF, INF));
  rep(i, 0, N) {
    auto x = lower_bound(all(dp), v[i], [&](P a, P b) {
      return a.first < b.first and a.second < b.second;
    });
    *x = v[i];
    m[v[i]] = x - dp.begin();
  }

  rep(i, 0, N) { cout << m[w[i]] << endl; }

  return 0;
}
