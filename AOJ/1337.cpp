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
//エラトステネスの篩
vector<char> eratos(int n) {
  vector<char> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++)
    if (is_prime[i]) {
      int j = i + i;
      while (j <= n) {
        is_prime[j] = false;
        j += i;
      }
    }
  return is_prime;
}
//戻り値: n以下の素数
vector<int> get_primes(int n) {
  vector<char> is_prime = eratos(n);
  vector<int> primes;
  for (int i = 0; i < n + 1; i++)
    if (is_prime[i])
      primes.emplace_back(i);
  return primes;
}
template <typename T> vector<T> compress(vector<T> &a, vector<T> &b) {
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
  cout << fixed << setprecision(12);

  auto prime = get_primes(300);

  int N;
  while (cin >> N, N) {
    vector<int> x1(N), y1(N), x2(N), y2(N);
    rep(i, 0, N) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    auto zipx = compress(x1, x2), zipy = compress(y1, y2);
    dump(zipx, zipy);
    vector<vector<int>> field(zipx.size(), vector<int>(zipy.size(), 1));

    rep(i, 0, N) {
      dump(x1[i], x2[i], y1[i], y2[i]);
      rep(x, x1[i], x2[i]) rep(y, y2[i], y1[i]) { field[x][y] *= prime[i]; }
    }

    rep(i,0,field.size()){
      rep(j,0,field[i].size())cout<<field[i][j]<<(j==field[i].size()-1?'\n':' ');
    }
    set<int> s;
    for (auto a : field)
      for (auto b : a)
        s.insert(b);
    cout << s.size() << endl;
  }

  return 0;
}
