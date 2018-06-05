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
int N, M;
bool inrange(int x, int y) { return 1 <= x and x <= N and 1 <= y and y <= M; }
struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
};
struct Line {
  Point p1, p2;
  Line() {}
  Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> N >> M;
  int r, c;
  cin >> r >> c;
  string S;
  cin >> S;

  set<pair<int, int>> s;
//  s.insert(make_pair(r, c));

  rep(i, 0, S.size()) {

    int a = r, b = c;

    if (S[i] == 'U') {
      a = 1;
    } else if (S[i] == 'D') {
      a = N;
    } else if (S[i] == 'L') {
      b = 1;
    } else if (S[i] == 'R') {
      b = M;
    }

    for (auto p : s) {
      if (S[i] == 'U') {
        if (p.second == c and p.first < r) {
          chmax(a, p.first + 1);
        }
      }

      else if (S[i] == 'D') {
        if (p.second == c and p.first > r) {
          chmin(a, p.first - 1);
        }
      }

      else if (S[i] == 'L') {
        if (p.first == r and p.second < c) {
          chmax(b, p.second + 1);
        }
      } else if (S[i] == 'R') {
        if (p.first == r and p.second > c) {
          chmin(b, p.second - 1);
        }
      }
    }

    if (inrange(a, b)) {
      s.insert(make_pair(r, c));
      r = a;
      c = b;
    }

    cout << r << " " << c << " " << endl;
  }

  return 0;
}
