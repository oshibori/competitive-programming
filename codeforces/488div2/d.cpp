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

set<int> and_set(set<int> a, set<int> b) {
  set<int> ret;
  for (auto x : b) {
    if (a.count(x))
      ret.insert(x);
  }
  return ret;
}
set<int> p_to_set(pair<int, int> p) {
  set<int> ret;
  ret.insert(p.first);
  ret.insert(p.second);
  return ret;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> a(N);
  rep(i, 0, N) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first > a[i].second)
      swap(a[i].first, a[i].second);
  }
  vector<pair<int, int>> b(M);
  rep(i, 0, M) {
    cin >> b[i].first >> b[i].second;
    if (b[i].first > b[i].second)
      swap(b[i].first, b[i].second);
  }

  set<int> ans;

  rep(i, 0, N) {
    rep(j, 0, M) {
      dump(a[i], b[j]);
      auto u = and_set(p_to_set(a[i]), p_to_set(b[j]));
      dump(u);
      if (u.size() >= 1) {
        ans.insert(*u.begin());
      }
    }
  }
  /*
    dump(ans);
    dump(ans.size());
    if (ans.size() == 1) {
      cout << *ans.begin() << endl;
    }
    else{
  */
  int f = 0;
  vector<int> xxxxx;
  for (auto x : ans) {
    rep(i, 0, N) {
      if (p_to_set(a[i]).count(x)) {
        rep(j, 0, M) {
          if (and_set(p_to_set(a[i]), p_to_set(b[j])).size() == 1) {
        int cnt = 0;
            rep(k, 0, N) {
              if (and_set(p_to_set(b[j]), p_to_set(a[k])).size() == 1) {
                cnt++;
              }
            }
            if (cnt == 1) {
              f++;
              xxxxx.push_back(x);
            }
          }
        }
      }
    }
  }

  if (f > 0) {
    if (f == 1) {
      cout << xxxxx[0] << endl;
    } else
      cout << 0 << endl;

  } else {
    cout << -1 << endl;
  }

  return 0;
}
