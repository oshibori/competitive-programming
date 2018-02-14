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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int ans = 0;
  loop(N) {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int M;
    cin >> M;
    vector<int> x(M), y(M), z(M);
    rep(i, 0, M) cin >> x[i] >> y[i] >> z[i];
    int sx = *min_element(all(x));
    int ex = *max_element(all(x));
    int sy = *min_element(all(y));
    int ey = *max_element(all(y));
    int sz = *min_element(all(z));
    int ez = *max_element(all(z));

    ans ^= sx ;ans^= X - (ex + 1);
    ans ^= sy ;ans^= Y - (ey + 1);
    ans ^= sz ;ans^= Z - (ez + 1);
  }
  cout << (ans == 0 ? "LOSE" : "WIN") << endl;

  return 0;
}
