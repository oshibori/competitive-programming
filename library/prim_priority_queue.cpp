#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o)                                                                \
  if (DBG) {                                                                   \
    cerr << #o << " " << o << endl;                                            \
  }
#define dumpc(o)                                                               \
  if (DBG) {                                                                   \
    cerr << #o;                                                                \
    for (auto &e : (o))                                                        \
      cerr << " " << e;                                                        \
    cerr << endl;                                                              \
  }
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define each(it, c) for (auto it = (c).begin(); it != (c).end(); it++)
#define all(c) c.begin(), c.end()
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int W(1), B(0);
int prim(vector<vector<pair<int, int>>> &M) {
  int n = M.size(); //    Don't forget initializing!!!!!
  vector<int> d(n, INF), color(n, W);
  d[0] = 0;
  priority_queue<pair<int, int>> pq; // d[v], v
  pq.push(make_pair(0, 0));
  while (!pq.empty()) {
    pair<int, int> f(pq.top());
    pq.pop();
    color[f.second] = B;
    if (d[f.second] < f.first * (-1))
      continue;
    rep(i, 0, M[f.second].size()) {
      pair<int, int> u(M[f.second][i]);
      if (color[u.first] != B && u.second < d[u.first]) {
        d[u.first] = u.second;
        pq.push(make_pair(d[u.first] * (-1), u.first));
      }
    }
  }
  return accumulate(all(d), 0) / 100 - d.size() + 1;
}
signed main() {
  int n;
  while (cin >> n, n) {
    vector<vector<pair<int, int>>> M(n, vector < pair<int, int>>()); // dist,cost
    int m;
    cin >> m;
    rep(i, 0, m) {
      int a, b, d;
      char c;
      cin >> a >> c >> b >> c >> d;
      M[a].push_back(make_pair(b, d));
      M[b].push_back(make_pair(a, d));
    }
    cout << prim(M) << endl;
  }
  return 0;
}
