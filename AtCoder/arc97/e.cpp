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

template <typename T> struct BinaryIndexedTree {
  // 1-indexed
  int n;
  vector<T> d;
  // d[x] が管理する区間の長さは，x の最も下の立っているビット(x&-x)
  BinaryIndexedTree(int m) : n(m) {
    // 0 以外の値で初期化をするとき
    // ・add を 𝑁 回呼び出せば 𝑂(𝑁 log 𝑁)
    // ・𝑣𝑥 = 1 で初期化するなら bit[x] = x & -x; (x&-x は区間の長さ)
    // ・一般には bit[x] を 𝑣𝑥 で初期化したのち
    //   for (int x = 1; x < N; ++x) bit[x + (x & -x)] += bit[x];
    d.assign(m + 1, 0);
  }
  T sum(int a, int b) { return sum(b) - sum(a - 1); }
  T sum(int i) {
    // iから0にiの最も下の立っているbitを使って到達する最短距離
    // 次に足すべき区間は，番号から区間の長さを引くと求まる
    T ret(0);
    for (int j = i; j > 0; j -= j & (-j))
      ret += d[j];
    return ret;
  }
  void add(int i, T x) {
    // iからnにiの最も下の立っているbitを使って到達する最短距離
    // 次に更新すべき区間は，番号に区間の長さを足すと求まる
    for (int j = i; j <= n; j += j & (-j))
      d[j] += x;
  }
  int lower_bound(T w) {
    // 二分木の分かれ方に従って二分探索する
    // 左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
    // (index/2)
    // ちょうど BIT がもっている情報，𝑂(1) 時間で得られる
    //
    if (w <= 0)
      return 0;
    int x(0), y;
    for (y = 1; 2 * y <= n; y <<= 1)
      ;
    for (int k = y; k > 0; k >>= 1) {
      if (x + k <= n && d[x + k] < w) {
        w -= d[x + k];
        x += k;
      }
    }
    return x + 1;
  }
};

template <typename T> vector<T> compress(vector<T> &a) {
  // 座標圧縮
  vector<T> ret;
  ret.insert(ret.end(), all(a));
  sort(all(ret));
  ret.erase(unique(all(ret)), ret.end());
  rep(i, 0, a.size()) a[i] = distance(ret.begin(), lower_bound(all(ret), a[i]));
  return ret;
}

int theNunberOfInversion(vector<int> &a) {
  compress(a);
  BinaryIndexedTree<int> bit(a.size());

  int ans(0);
  rep(i, 0, a.size()) {
    ans += i - bit.sum(a[i]);
    bit.add(a[i], 1);
  }
  return ans;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  vector<pair<char, int>> v(2 * N + 1);
  rep(i, 1, 2 * N + 1) { cin >> v[i].first >> v[i].second; }

  vector<vector<int>> costb(N + 1, vector<int>(N + 1)),
      costw(N + 1, vector<int>(N + 1));

  rep(j, 0, N + 1) {
    BinaryIndexedTree<int> bitb(N), bitw(N);
    int b = 0, w = 0;
    rep(i, 1, 2 * N + 1) {
      if (v[i].first == 'B') {
        costb[v[i].second - 1][j] = b + w - bitb.sum(v[i].second);
        bitb.add(v[i].second, 1);
        b++;
      } else {
        if (v[i].second > j)
          w++;
      }
    }
  }
  rep(i, 0, N + 1) {
    BinaryIndexedTree<int> bitb(N), bitw(N);
    int b = 0, w = 0;
    rep(j, 1, 2 * N + 1) {
      if (v[j].first == 'W') {
        costw[i][v[j].second - 1] = b + w - bitw.sum(v[j].second);
        bitw.add(v[j].second, 1);
        w++;
      } else {
        if (v[j].second > i)
          b++;
      }
    }
  }

  vector<vector<int>>dp(N+1,vector<int>(N+1,INF));
  dp[0][0]=0;
  
  rep(i,0,N+1)rep(j,0,N+1){
    if(i-1>=0)chmin(dp[i][j],dp[i-1][j]+costb[i-1][j]);
    if(j-1>=0)chmin(dp[i][j],dp[i][j-1]+costw[i][j-1]);
  }
  dump(dp);
  cout<<dp[N][N]<<endl;

  return 0;
}
