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

  string s, t;
  cin >> s >> t;

  map<char, int> sm, tm;

  rep(i, 0, s.size()) sm[s[i]]++;
  rep(i, 0, t.size()) tm[t[i]]++;

  if (sm['A'] < tm['A'] || sm['B'] > tm['B']) {
    cout << "NO" << endl;
    return 0;
  }

  sm['A'] = sm['B'] = tm['A'] = tm['B'] = 0;

  if (sm != tm) {
    // cout << "sm" << endl;
    // for (auto e : sm) {
    //  cout << e.first << " " << e.second << endl;
    //}
    // cout << "tm" << endl;
    // for (auto e : tm) {
    //  cout << e.first << " " << e.second << endl;
    //}
    cout << "NO" << endl;
    return 0;
  }

  int i = 0, j = 0;
  vector<pair<string, string>> v;
  while (i < s.size() && j < t.size()) {
    string a, b;
    while (i < s.size() && (s[i] == 'A' || s[i] == 'B')) {
      a.push_back(s[i]);
      i++;
    }
    while (j < t.size() && (t[j] == 'A' || t[j] == 'B')) {
      b.push_back(t[j]);
      j++;
    }

    cout << (a.empty() ? "empty" : a) + "   " + (b.empty() ? "empty" : b)
         << endl;

    v.push_back(make_pair(a, b));
    i++;
    j++;
  }

  bool ans = true;
  rep(k, 0, v.size()) {
    string a = v[k].first, b = v[k].second;

    int s_A = count(all(s), 'A'), s_B = count(all(s), 'B');
    int t_A = count(all(t), 'A'), t_B = count(all(t), 'B');

    if(a.empty()&&t_A){
      ans=false;
    }
    if(b.empty()&&s_B){
      ans=false;
    }

    bool f = true, g = true;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i] == b[j]) {
        i++;
        j++;
      }

      else if (a[i] == 'A' && b[j] == 'B') {
        j++;
      }

      else {
        ans = false;
        break;
      }
    }

//    if (i == a.size()) {
//      if (count(b.begin() + j, b.end(), 'A'))
//        f = false;
//    }
//    if (j == b.size()) {
//      if (count(a.begin() + i, a.end(), 'B'))
//        f = false;
//    }

    reverse(all(a));
    reverse(all(b));
    i=0,j=0;
    while (i < a.size() && j < b.size()) {
      if (a[i] == b[j]) {
        i++;
        j++;
      }

      else if (a[i] == 'A' && b[j] == 'B') {
        j++;
      }

      else {
        ans = false;
        break;
      }
    }

//    if (i == a.size()) {
//      if (count(b.begin() + j, b.end(), 'A'))
//        g = false;
//    }
//    if (j == b.size()) {
//      if (count(a.begin() + i, a.end(), 'B'))
//        g = false;
//    }

  }

  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
