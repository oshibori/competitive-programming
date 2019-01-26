#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define ll1 1ll
#define ONE 1ll
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
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &p) {
	is >> p.first >> p.second;
	return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &p) {
	os << p.first << " " << p.second;
	return os;
}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}
/*
typedef __int128_t Int;
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
std::ostream::sentry s(dest);
  if (s) {
	__uint128_t tmp = value < 0 ? -value : value;
	char buffer[128];
	char *d = std::end(buffer);
	do {
	  --d;
	  *d = "0123456789"[tmp % 10];
	  tmp /= 10;
	} while (tmp != 0);
	if (value < 0) {
	  --d;
	  *d = '-';
	}
	int len = std::end(buffer) - d;
	if (dest.rdbuf()->sputn(d, len) != len) {
	  dest.setstate(std::ios_base::badbit);
	}
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
	if ('0' <= s[i] && s[i] <= '9')
	  ret = 10 * ret + s[i] - '0';
  return ret;
}
*/

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
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

struct Rectangle { int height;  int pos; };
int getLargestRectangle(vector<int>h) {
	stack<Rectangle> S;
	int maxv = 0;
	h.emplace_back(0);
	int W = h.size();
	//  右端がh[i]のとき、{j | j<i, h[j]>h[i]}の情報はいらないので、それまでの長方形を計算する
	// stackの中を単調増加に保つ
	for (int i = 0; i < W; i++) {
		Rectangle rect;
		rect.height = h[i];
		rect.pos = i;
		if (S.empty()) {
			S.push(rect);
		}
		else {
			if (S.top().height < rect.height) {
				S.push(rect);
			}
			else if (S.top().height > rect.height) {
				int target = i;
				while (!S.empty() && S.top().height >= rect.height) {
					Rectangle pre = S.top(); S.pop();
					int area = (pre.height + 1) * (1 + i - pre.pos);
					maxv = max(maxv, area);
					target = pre.pos;
				}
				rect.pos = target;
				S.push(rect);
			}
		}
	}
	return maxv;
}

// can use:1, cannot use:0
int getLargestRectangle(const vector<vector<int>>&v) {
	int H = v.size(), W = v[0].size();
	enum { NG, OK };
	vector<int>h(W, 0);
	int maxv = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (v[i][j] == OK)h[j]++;
			else h[j] = 0;
		}
		maxv = max(maxv, getLargestRectangle(h));
	}
	return maxv;
}
signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int H, W; cin >> H >> W;
	vector<string>S(H); rep(i, 0, H) { cin >> S[i]; }
	vector<vector<int>>v(H, vector<int>(W));
	rep(i, 0, H)rep(j, 0, W) {
		if (S[i][j] == '#')v[i][j] = 1;
		else v[i][j] = 0;
	}
	vector<vector<int>>w(H - 1, vector<int>(W - 1));
	rep(i, 0, H - 1)rep(j, 0, W - 1) {
		int x = v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1];
		w[i][j] = not (x % 2);
	}
	cout << max({ getLargestRectangle(w),H,W }) << endl;


	return 0;
}
