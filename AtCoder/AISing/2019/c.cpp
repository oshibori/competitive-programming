//#include "bits/stdc++.h"
//
//using namespace std;
//#ifdef _DEBUG
//#define _GLIBCXX_DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
//#define int long long
//#define ll long long
//#define ll1 1ll
//#define ONE 1ll
//#define DBG 1
//#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
//#define loop(n) rep(loop, (0), (n))
//#define all(c) begin(c), (c)
//const int INF =
//sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//const double PI = acos(-1);
//const double EPS = 1e-9;
//#define fi first
//#define se second
//#define pb push_back
//#define eb emplace_back
//using pii = pair<int, int>;
//// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
//template <typename T, typename S>
//istream &operator>>(istream &is, pair<T, S> &p) {
//	is >> p.first >> p.second;
//	return is;
//}
//template <typename T, typename S>
//ostream &operator<<(ostream &os, pair<T, S> &p) {
//	os << p.first << " " << p.second;
//	return os;
//}
//
//template <typename T> void printvv(const vector<vector<T>> &v) {
//	cerr << endl;
//	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
//		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
//			cerr << "INF";
//		}
//		else
//			cerr << v[i][j];
//		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
//	}
//	cerr << endl;
//}
///*
//typedef __int128_t Int;
//std::ostream &operator<<(std::ostream &dest, __int128_t value) {
//std::ostream::sentry s(dest);
//  if (s) {
//	__uint128_t tmp = value < 0 ? -value : value;
//	char buffer[128];
//	char *d = std::(buffer);
//	do {
//	  --d;
//	  *d = "0123456789"[tmp % 10];
//	  tmp /= 10;
//	} while (tmp != 0);
//	if (value < 0) {
//	  --d;
//	  *d = '-';
//	}
//	int len = std::(buffer) - d;
//	if (dest.rdbuf()->sputn(d, len) != len) {
//	  dest.setstate(std::ios_base::badbit);
//	}
//  }
//  return dest;
//}
//
//__int128 parse(string &s) {
//  __int128 ret = 0;
//  for (int i = 0; i < s.length(); i++)
//	if ('0' <= s[i] && s[i] <= '9')
//	  ret = 10 * ret + s[i] - '0';
//  return ret;
//}
//*/
//
//#ifndef _DEBUG
//#define printvv(...)
//#endif
//void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
//void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
//template <class T> bool chmax(T &a, const T &b) {
//	if (a < b) {
//		a = b;
//		return true;
//	}
//	return false;
//}
//template <class T> bool chmin(T &a, const T &b) {
//	if (a > b) {
//		a = b;
//		return true;
//	}
//	return false;
//}
//vector<vector<int>>vec;
//int n;
//vector<int>color;
//void bsf(int s, int c) {
//	queue<int>q;
//	q.push(s);
//	color[s] = c;
//	while (!q.empty()) {
//		int u = q.front(); q.pop();
//		rep(v, 0, vec[u].size()) {
//			if (color[vec[u][v]] != -1)continue;
//			color[vec[u][v]] = c;
//			q.push(vec[u][v]);
//		}
//	}
//}
//void assignColor() {
//	// O(|V|+|E|)
//	rep(i, 0, n) {
//		if (color[i] == -1)bsf(i, i);
//	}
//}
//int H, W;
//bool inrange(int x, int y) { return 0 <= x and x < H and 0 <= y and y < W; }
//signed main(signed argc, char *argv[]) {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cout << fixed << setprecision(12);
//
//	cin >> H >> W;
//	n = H * W;
//	vec = vector<vector<int>>(n); color = vector<int>(n, -1);
//	int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//	vector<string>v(H); rep(i, 0, H) { cin >> v[i]; }
//	rep(i, 0, H) {
//		rep(j, 0, W) {
//			rep(k, 0, 4) {
//				int x = i + dx[k], y = j + dy[k];
//				if (inrange(x, y) and v[i][j] != v[x][y]) {
//					vec[i*W + j].emplace_back(x*W + y);
//				}
//			}
//
//		}
//	}
//	assignColor();
//	vector<int>a(n), b(n);
//	rep(i, 0, H) {
//		rep(j, 0, W) {
//			if (v[i][j] == '.') {
//				a[color[i*W + j]]++;
//			}
//			else {
//				b[color[i*W + j]]++;
//			}
//		}
//	}
//	int ans = 0;
//	rep(i, 0, n) {
//		ans += a[i] * b[i];
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}
