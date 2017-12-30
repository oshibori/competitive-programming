#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
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
  cout<<setprecision(12);

  int N, r;
  cin >> N >> r;
  vector<int> x(N);
  rep(i, 0, N) { cin >> x[i]; }
  vector<double> y;
  rep(i, 0, N) {
    bool f = false;
    rrep(j, 0, y.size()) {
      double dx = abs(x[i] - x[j]);
      double dy = sqrt(4 * r*r - dx * dx);

      if (abs(dx * dx + dy * dy - 4*r * r) < EPS) {
        f = true;
        y.push_back(y[j] + dy);
        break;
      }
    }

    if (!f)
      y.push_back(r);
  }

  rep(i, 0, N) cout << y[i] << (i == N - 1 ? '\n' : ' ');

  return 0;
}
