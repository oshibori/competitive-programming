#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
using pii = pair<int, int>;
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
template <typename T> vector<T> compress(vector<T> &a, vector<T> &b) {
  // 座標圧縮
  vector<T> ret;
  ret.insert(ret.end(), all(a));
  ret.insert(ret.end(), all(b));
  sort(all(ret));
  ret.erase(unique(all(ret)), ret.end());
  rep(i, 0, a.size()) a[i] = distance(ret.begin(), lower_bound(all(ret), a[i]));
  rep(i, 0, b.size()) b[i] = distance(ret.begin(), lower_bound(all(ret), b[i]));
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W;
  cin >> H >> W;
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<int> x1, y1, x2, y2;
  rep(i, 0, N) rep(j, 0, M) {
    if (A[i][j] == '#') {
      x1.push_back(i);
      y1.push_back(j);
      x2.push_back(i + H - N + 1);
      y2.push_back(j + W - M + 1);
      dump(x1.back(), y1.back(), x2.back(), y2.back());
    }
  }
  if (x1.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  //  x1.push_back(INF);
  //  y1.push_back(INF);
  //  x2.push_back(INF);
  //  y2.push_back(INF);
  auto zipx = compress(x1, x2), zipy = compress(y1, y2);
  dump(zipx, zipy);
  dump(x1, x2);
  dump(y1, y2);
  vector<vector<int>> field(zipx.size(), vector<int>(zipy.size(), 0));
  rep(i, 0, x1.size()) {
    field[x1[i]][y1[i]]++;
    field[x2[i]][y2[i]]++;
    field[x1[i]][y2[i]]--;
    field[x2[i]][y1[i]]--;
    if (DBG) {
      rep(i, 0, field.size()) {
        rep(j, 0, field[0].size()) {
          cout << field[i][j] << (j == field[0].size() - 1 ? '\n' : ' ');
        }
      }
    }
    cout << endl;
  }
  rep(i, 0, zipx.size()) rep(j, 1, zipy.size()) field[i][j] += field[i][j - 1];
  rep(i, 0, zipy.size()) rep(j, 1, zipx.size()) field[j][i] += field[j - 1][i];

  if (DBG) {
    rep(i, 0, field.size()) {
      rep(j, 0, field[0].size()) {
        cout << field[i][j] << (j == field[0].size() - 1 ? '\n' : ' ');
      }
    }
  }
  int ans(0);
  rep(i, 0, zipx.size() - 1) rep(j, 0, zipy.size() - 1) {
    if (field[i][j])
      ans += (zipx[i + 1] - zipx[i]) * (zipy[j + 1] - zipy[j]);
  }
  cout << ans << endl;
  return 0;
}
