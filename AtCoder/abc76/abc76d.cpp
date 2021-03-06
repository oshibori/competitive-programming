#include <bits/stdc++.h>
using namespace std;

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

  int N;
  cin >> N;
  vector<int> t(N + 1);
  rep(i, 1, N + 1) {
    cin >> t[i];
    t[i] *= 2;
    t[i] += t[i - 1];
  }
  vector<double> v(N);
  rep(i, 0, N) {
    cin >> v[i];
    v[i] /= 2;
  }

  vector<double> time(t.back() + 1, INF);
  time[0] = time[time.size() - 1] = 0;

  rep(i, 1, N + 1) {
    rep(j, t[i - 1], t[i] + 1) { chmin(time[j], v[i - 1]); }
  }

  rep(i, 0, N + 1) {
    rep(j, t[i] + 1, t[i + 1] + 1) { chmin(time[j], time[j - 1] + 0.25); }
    rrep(j, t[i], t[i + 1]) { chmin(time[j], time[j + 1] + 0.25); }
  }
  cout << accumulate(all(time), 0.0) << endl;

  return 0;
}
