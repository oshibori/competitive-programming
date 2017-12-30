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

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
pair<int, int> sp, ep;
int N, M;

int inrange(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector<string> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  string s;
  cin >> s;

  rep(i, 0, N) rep(j, 0, M) {
    if (v[i][j] == 'S') {
      v[i][j] = '.';
      sp.first = i;
      sp.second = j;
    }
    if (v[i][j] == 'E') {
      v[i][j] = '.';
      ep.first = i;
      ep.second = j;
    }
  }
  vector<int> p = {0, 1, 2, 3};
  int ans(0);
  do {
    int x = sp.first, y = sp.second;
    rep(i, 0, s.size()) {
      int op = s[i] - '0';
      x += dx[p[op]];
      y += dy[p[op]];
      if (!inrange(x, y) || v[x][y] == '#') {break;}
      if (make_pair(x, y) == ep) {
        ans++;
        break;
      }
    }
  } while (next_permutation(all(p)));

  cout << ans << endl;

  return 0;
}
