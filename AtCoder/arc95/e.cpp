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
using pii = pair<int, int>;
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

int H, W;
vector<string> S, T;
bool check() {
  map<string, int> mp;
  rep(j, 0, W) {
    string s;
    rep(i, 0, H) {
      if (T[i][j] == '#')
        s += T[H - 1 - i][j];
      else
        s += T[i][j];
    }
    string t = s;
    reverse(all(t));
    if (s <= t)
      mp[s]++;
    else
      mp[t]--;
  }
  int c = 0;
  for (auto p : mp) {
    dump(p);
    if (p.second == 0)
      continue;
    string s = p.first;
    string t = s;
    reverse(all(t));

    if (s != t)
      return false;
    else {
      if (p.second & 1){
        c++;
      }
      if(c==2)return false;
    }
  }
  return true;
}
bool dfs(int s, int k) {
  dump(s, k);
  if (s == 0) {
    return check();
  }

  int c = 0;
  while (~s >> c & 1)
    c++;
  T[k] = S[c];
  rep(i, c + 1, H) {
    if (s >> i & 1) {
      T[H - 1 - k] = S[i];
      if (dfs(s ^ (1 << c) ^ (1 << i), k + 1))
        return true;
    }
  }
  return false;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);

  cin >> H >> W;
  S.resize(H);
  T.resize(H);
  rep(i, 0, H) { cin >> S[i]; }
  if (H & 1) {
    S.push_back(string(W, '#'));
    H++;
    T.push_back(string());
  }
  cout << (dfs((1 << H) - 1, 0) ? "YES" : "NO") << endl;

  return 0;
}
