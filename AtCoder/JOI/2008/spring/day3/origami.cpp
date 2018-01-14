#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
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
struct Point {
  int x, y;
};
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}
vector<int> compress(vector<int> &a, vector<int> &b) {
  vector<int> ret(a);
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

  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  map<pair<int, int>, int> m;
  rep(i, 0, N) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    rep(i, a, c + 1) rep(j, b, d + 1) m[make_pair(i, j)]++;
  }
  map<int, int> cnt;
  for (auto &o : m) {
    cnt[o.second]++;
  }
  auto ans = max_element(all(cnt));
  cout << ans->first << endl << ans->second << endl;
  /*
  vector<int> p(N), q(N), r(N), s(N);
  rep(i, 0, N){ cin >> p[i] >> q[i] >> r[i] >> s[i];r[i]++,s[i]++;}
  auto x = compress(p, r), y = compress(q, s);
  dump(x);dump(y);
  dump(p);
  dump(q);
  dump(r);
  dump(s);
  vector<vector<int>>v(x.size(),vector<int>(y.size(),0));
  memset(v,0,sizeof(v));

  rep(i, 0, N) { rep(j, p[i], r[i]) rep(k, q[i], s[i]) v[j][k]++; }
  if(DBG){
    cout<<endl;
    rep(i,0,x.size())rep(j,0,y.size())cout<<v[i][j]<<(j==y.size()-1?'\n':' ');
  }
  map<int, int> m;
  rep(i, 0, x.size() - 1) rep(j, 0, y.size() - 1) {
    m[v[i][j]] += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
  }
  auto ans = max_element(all(m));
  dump(m);
  cout<<ans->first<<endl<<ans->second<<endl;

  */
  return 0;
}
