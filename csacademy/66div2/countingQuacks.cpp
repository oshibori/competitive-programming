#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;
  vector<int> x(N);
  map<int, int> m;
  rep(i, 0, N) {
    cin >> x[i];
    m[x[i]]++;
  }
  sort(all(x));
  x.erase(unique(all(x)), x.end());
  vector<int> v(T + 1, 0);
  rep(i, 0, x.size()) {
    for (int j = x[i]; j < T + 1; j += x[i])
      v[j] += m[x[i]];
  }
  auto g = max_element(1 + all(v));
  auto h = count(1 + all(v), *g);
  cout << *g << " " << h << endl;
}
