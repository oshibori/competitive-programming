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
const int N = 10;
const int B = 1;
const int W = -1;
int n, m, p;
vector<vector<vector<int>>> cube;
vector<vector<int>> h;
vector<int> dx = {1, 0, 0, 1, -1, 0, 0, 1, -1, 1, -1, 1, -1};
vector<int> dy = {0, 1, 0, 1, 1, 1, -1, 0, 0, 1, 1, 1, 1};
vector<int> dz = {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, -1, -1};

bool inrange(int x, int y, int z) {
  return 0 <= x&&x < n && 0 <= y&&y < n && 0 <= z&&z < n;
}
int count(int x, int y, int z, int d, int t, int r) {
  cerr<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
  if (cube[x][y][z] != t)
    return 0;
  int nx = x + dx[d] * r, ny = y + dy[d] * r, nz = z + dz[d] * r;
  return inrange(nx, ny, nz) ? count(nx, ny, nz, d, t, r) + 1 : 1;
}
int check(int a, int b, int c) {
  rep(l, 0, 13) {
    int cnt = 0;
    cnt += count(a, b, h[a][b] - 1, l, c, 1);
    cnt += count(a, b, h[a][b] - 1, l, c, -1);
    cnt--;
    if (cnt >= m)
      return c;
  }
  return 0;
}
signed main() {

  while (cin >> n >> m >> p && n) {
    cube = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n, vector<int>(n, 0)));
    h = vector<vector<int>>(n, vector<int>(n, 0));
    int winner = 0;
    int fin = 0;
    vector<int> X(p), Y(p);
    for (int i = 0; i < p; i++) {
      cin >> X[i] >> Y[i];
      X[i]--, Y[i]--;
    }
    for (int i = 0; i < p; i++) {
      int x = X[i], y = Y[i];
      if (i & 1)
        cube[x][y][h[x][y]++] = W;
      else
        cube[x][y][h[x][y]++] = B;

      winner = check(x, y, (i & 1 ? W : B));
      cerr << "i = " << i << endl;
      fin = i + 1;
      if (winner != 0)
        break;
    }

    if (winner == B)
      cout << "Black " << fin << endl;
    else if (winner == W)
      cout << "White " << fin << endl;
    else
      cout << "Draw" << endl;
  }

  return 0;
}
