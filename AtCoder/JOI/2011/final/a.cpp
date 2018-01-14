#define _GLIBCXX_DEBUG
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

vector<int> operator+(const vector<int> x, const vector<int> y) {
  vector<int> ret(x);
  rep(i, 0, ret.size()) ret[i] += y[i];
  return ret;
}
vector<int> operator-(const vector<int> x, const vector<int> y) {
  vector<int> ret(x);
  rep(i, 0, ret.size()) ret[i] -= y[i];
  return ret;
}
ostream &operator<<(ostream &os, const vector<int> &x) {
  os << x[0];
  rep(i, 1, x.size()) { os << ' ' << x[i]; }
  return os;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  enum mark { J, O, I };

  int N, M, K;
  cin >> N >> M >> K;
  // vector<vector<vector<int>>> v(N + 1,
  //                              vector<vector<int>>(M + 1, vector<int>(3,
  //                              0)));
  int v[1010][1010][3];
  memset(v, 0, sizeof(v));
  rep(i, 0, N) {
    string s;
    cin >> s;
    rep(j, 0, M) {
      if (s[j] == 'J')
        v[i + 1][j + 1][J] = 1;
      else if (s[j] == 'O')
        v[i + 1][j + 1][O] = 1;
      else
        v[i + 1][j + 1][I] = 1;
    }
  }

  vector<mark> x{J, O, I};
  // rep(i, 0, N + 1) rep(j, 1, M + 1)for(auto &o:x) v[i][j][o] += v[i][j -
  // 1][o];
  // rep(j, 0, M + 1) rep(i, 1, N + 1)for(auto &o:x) v[i][j][o] += v[i -
  // 1][j][o];
  rep(i, 1, N + 1) rep(j, 1, M + 1) for (auto &o : x) v[i][j][o] +=
      v[i][j - 1][o] + v[i - 1][j][o] - v[i - 1][j - 1][o];

  rep(i, 0, K) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> result(3, 0);
    for (auto &o : x) {
      result[o] =
          v[c][d][o] + v[a - 1][b - 1][o] - v[a - 1][d][o] - v[c][b - 1][o];
    }
    // cout << v[c][d] + v[a - 1][b - 1] - v[a - 1][d] - v[c][b - 1] << endl;
    // cout<<result<<endl;
    cout << result[J] << " " << result[O] << " " << result[I] << endl;
  }

  return 0;
}
