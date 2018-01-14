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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> v(N);
  rep(i, 0, N) { cin >> v[i]; }
  sort(all(v));
  set<int> s;
  rep(i, 0, N) s.insert(v[i]);
  vector<int> w;
  rep(i, 1, 2 * N + 1) {
    if (s.count(i))
      continue;
    else
      w.push_back(i);
  }
  dump(v);
  dump(w);
  v.push_back(INF);
  w.push_back(INF);

  int i, j, cnt, field;
  for (i = j = cnt = field = 0; i < N && j < N; cnt++) {
    if (cnt & 1) {
      int index = N;
      rep(k, 0, N) if (field < w[k] && w[k] < w[index]) index = k;
      if (index == N)
        field = 0;
      else {
        field = w[index];
        w[index] = INF;
        i++;
      }

    } else {
      int index = N;
      rep(k, 0, N) if (field < v[k] && v[k] < v[index]) index = k;
      if (index == N)
        field = 0;
      else {
        field = v[index];
        v[index] = INF;
        j++;
      }
    }
  }

  cout<<N-i<<endl<<N-j<<endl;
  return 0;
}
