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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  rep(i, 0, N) { cin >> p[i]; }
  vector<int> c(N);
  rep(i, 0, N) { cin >> c[i]; }

  map<int,int>ans;
  vector<pair<int, int>> v(N);
  rep(i, 0, N) {
    v[i].first = p[i];
    v[i].second = c[i];
  }
  sort(all(v));
  auto comp = [](pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(
      comp);

  int sum=0;
  rep(i,0,N){
    ans[v[i].first]=v[i].second+sum;

    pq.push(v[i]);
    sum+=v[i].second;
    if(pq.size()>K){
      auto z=pq.top();
      pq.pop();
      sum-=z.second;
    }
  }

  rep(i,0,N){
    cout<<ans[p[i]]<<endl;
  }


  return 0;
}
