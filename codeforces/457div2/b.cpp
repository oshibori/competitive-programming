#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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

  int N, K;
  cin >> N >> K;
  map<int, int> v;
  // priority_queue<int> pq;

  int size = 0;
  for (int i = 0, n = N; n; i++) {
    if (n & 1) {
      // v.push_back(i);
      // pq.push(i);
      v[i] = 1;
      size++;
    }
    n >>= 1;
  }
  // reverse(all(v));
  // dump(v);
  // dump(pq);

  if (size > K) {
    cout << "No" << endl;
    return 0;
  }

  while (size < K) {
    auto x = *v.rbegin();
    size -= x.second;
    int d = K - size;
    if (x.second * 2 <= d) {
      v[x.first - 1] += x.second * 2;
      size += x.second * 2;
      v.erase(x.first);
    } else {
      v[x.first - 1] += (d - x.second) * 2;
      v[x.first] -= d - x.second;
      size += d - x.second;
      if(v[x.first]==0)v.erase(x.first);
    }
  }
  /*
    while (pq.size() < K) {
      int x = pq.top();
      pq.pop();
      int y = K - pq.size();
      int i = 0, two = 1;
      while (two * two <= y) {
        two <<= 1;
        i++;
      }

      loop(two) { pq.push(x - i); }
    }

  */
  cout << "Yes" << endl;
  /*
  for (auto i = v.rbegin(); i != v.rend(); i++) {
    int a = i->second;
    int b = i->first;
    while (a--)
      cout << b << (b == v.begin()->first and a == 0 ? '\n' : ' ');
  }
  */
  vector<pair<int,int>>z;
  for(auto &o:v)z.push_back(o);
  sort(all(z),greater<int,int>());
  rrep(i,0,z.size()){
    while(z[i].second--)cout<<z[i].first<<(z[i].second==0 and i==0?'\n':' ');
  }

  return 0;
}
