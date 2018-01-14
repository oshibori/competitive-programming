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

vector<int> operator+(vector<int> x, vector<int> y) {
  rep(i, 0, x.size()) x[i] += y[i];
  return x;
}
vector<int> operator-(vector<int> x, vector<int> y) {
  rep(i, 0, x.size()) x[i] -= y[i];
  return x;
}
int operator*(vector<int> x, vector<int> y) {
  int sum = 0;
  rep(i, 0, x.size()) sum += x[i] * y[i];
  return sum;
}
vector<int> operator*(vector<vector<int>> x, vector<int> y) {
  vector<int> z(x.size());
  rep(i, 0, x.size()) z[i] = x[i] * y;
  return z;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int F = 5001;
  // map<int,map<int,int>> f;
  // map<pair<int,int>,int>f;
  vector<vector<bool>> f(F, vector<bool>(F, 0));
  vector<int> x(N), y(N);
  rep(i, 0, N) {
    cin >> x[i] >> y[i];
    f[x[i]][y[i]] = 1;
    // f[make_pair(x[i],y[i])]=1;
  }
  auto inrange = [&](vector<int> x) {
    return 0 <= x[0] and x[0] <= 5000 and 0 <= x[1] and x[1] <= 5000;
  };
  vector<vector<int>> left = {{0, -1}, {1, 0}}, right = {{0, 1}, {-1, 0}};
  int ans = 0;
  rep(i, 0, N) rep(j, i + 1, N) {
    vector<int> x1(2), x2(2);
    x1[0] = x[i], x1[1] = y[i];
    x2[0] = x[j], x2[1] = y[j];
    vector<int> v(2); //= x1 - x2;
    v[0]=x1[0]-x2[0];
    v[1]=x1[1]-x2[1];

    vector<int> x3(2); //= x2 + right * (x1 - x2);
    x3[0]=x2[0]+(x1[1]-x2[1]);
    x3[1]=x2[1]-(x1[0]-x2[0]);
    vector<int> x4(2); //= x1 + left * (x2 - x1);
    x4[0]=x1[0]-(x2[1]-x1[1]);
    x4[1]=x1[1]+(x2[0]-x1[0]);

    if (inrange(x3) and inrange(x4) and f[x3[0]][x3[1]] && f[x4[0]][x4[1]]) {
      // if (inrange(x3)and inrange(x4)and f[make_pair(x3[0],x3[1])] &&
      // f[make_pair(x4[0],x4[1])]) {
      chmax(ans, v[0] * v[0] + v[1] * v[1]);
    }
  }
  cout << ans << endl;

  return 0;
}
