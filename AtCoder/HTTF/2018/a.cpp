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
const int N = 100;
const int MAXQ = 1000;
int _A[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool inrange(int x, int y) { return 0 <= x and x < N and 0 <= y and y < N; }
struct Coordinate {
  int A[N][N];
  int X, Y, H, Q;
  Coordinate *parent, *self;
  Coordinate() : X(-1), Y(-1), H(-1), Q(0), parent(NULL), self(this) {
    rep(i, 0, N) rep(j, 0, N) { A[i][j] = _A[i][j]; }
  }
};
ostream &operator<<(ostream &os, const Coordinate &p) {
  os << "Q:" << p.Q << ", X:" << p.X << ", Y:" << p.Y << ", H:" << p.H << endl;
  rep(i, 0, N) rep(j, 0, N) os << p.A[i][j] << (j == N - 1 ? '\n' : ' ');
}

long long int eval(const Coordinate &p) {
  long long int b = 200000000;
  long long int loss = 0;
  rep(i, 0, N) rep(j, 0, N) {
    int x=(long long int)abs(p.A[i][j]); // * (long long int)abs(p.A[i][j]);
    loss += (x<0?x*x:x);
  }
  if (loss == 0)
    b += 1000 - p.Q;
  return b - loss;
}
bool operator<(const Coordinate &p, const Coordinate &q) {
  return eval(p) < eval(q);
}
pair<int, int> max(const Coordinate &p) {
  int x = 0, y = 0, v = p.A[x][y];
  rep(i, 0, N) rep(j, 0, N) {
    if (chmax(v, p.A[i][j])) {
      x = i, y = j;
    }
  }
  return make_pair(x, y);
}
pair<int, int> min(const Coordinate &p) {
  int x = 0, y = 0, v = p.A[x][y];
  rep(i, 0, N) rep(j, 0, N) {
    if (chmin(v, p.A[i][j])) {
      x = i, y = j;
    }
  }
  return make_pair(x, y);
}

Coordinate *sub(Coordinate *p, int X, int Y, int H) {
  Coordinate *ret = new Coordinate(*p);
  ret->X = X;
  ret->Y = Y;
  ret->H = H;
  ret->Q++;
  ret->parent = p;

  rep(i, 0, N) rep(j, 0, N) {
    ret->A[i][j] -= max(0, H - (abs(i - X) + abs(j - Y)));
  }
  return ret;
}
int getv(const Coordinate &p, pair<int, int> idx) {
  return p.A[idx.first][idx.second];
}
signed main() {

  // input
  rep(i, 0, N) rep(j, 0, N) { scanf("%d", &_A[i][j]); }
  // 1 <= H <= 100
  const int MAXH = 100;
  int X[MAXQ], Y[MAXQ], H[MAXQ];
  int Q = 0;

  // something cool
  Coordinate _p;
  const int W = 10;
  const int BEAMWIDTH = 7;
  priority_queue<Coordinate> pq;
  pq.push(_p);
  int ww[] = {10, 20, 40, 60, 80};
  loop(MAXQ) {
    priority_queue<Coordinate> tmp;
    for (int i = 0; i < BEAMWIDTH and pq.size() > 0; i++) {
      tmp.push(pq.top());
      // Coordinate xx(pq.top());
      // dump(&xx, xx.self);
      pq.pop();
    }
    while (pq.size()) {
      Coordinate xx(pq.top());
      pq.pop();
      delete xx.self;
    }
    pq = priority_queue<Coordinate>();
    while (tmp.size()) {
      Coordinate *p = new Coordinate(tmp.top());
      tmp.pop();
      pair<int, int> Midx = max(*p);
      pair<int, int> midx = min(*p);
      int x = Midx.first, y = Midx.second;
      int h = max(0, p->A[x][y]);
      // if (h == 0)
      //  break;
      rep(j, 0, 4) {
        Coordinate *xx = sub(p, x, y, ww[j]);
        Coordinate yy(*xx);
        yy.self = xx;
        pq.push(yy);
      }
    }
  }
  Coordinate cur = pq.top();
  dump(cur);
  Q = cur.Q;
  while (cur.parent != NULL) {
    dump(cur.parent);
    int i = cur.Q - 1;
    X[i] = cur.X;
    Y[i] = cur.Y;
    H[i] = cur.H;

    cur = *cur.parent;
  }

  // output
  cout << Q << endl;
  rep(i, 0, Q) printf("%d %d %d\n", X[i], Y[i], H[i]);

  return 0;
}
