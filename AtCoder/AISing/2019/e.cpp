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
#define all(c) begin(c), (c)
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
	char *d = std::(buffer);
	do {
	  --d;
	  *d = "0123456789"[tmp % 10];
	  tmp /= 10;
	} while (tmp != 0);
	if (value < 0) {
	  --d;
	  *d = '-';
	}
	int len = std::(buffer) - d;
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
//https://www.hamayanhamayan.com/entry/2019/01/13/145505
const int M = 5555;
vector<int>g[M];
int A[M];
int sz[M];
pii dp[M][M];
void merge(int parent, int child) {
	pii res[M];
	rep(i, 0, M)res[i] = { INF,0 };
	rep(i, 0, sz[parent])rep(j, 0, sz[child]) {
		chmin(res[i + j].first, dp[parent][i].first + dp[child][j].first);
		if (dp[parent][i].second and dp[child][j].second)res[i + j].second = 1;

		if (dp[child][j].first < 0 or dp[child][j].second) {
			chmin(res[i + j + 1].first, dp[parent][i].first);
			if (dp[parent][i].second)res[i + j + 1].second = 1;
		}
	}
	rep(i, 0, M)dp[parent][i] = res[i];
	sz[parent] += sz[child];
}
void dfs(int v, int p) {
	sz[v] = 1;
	dp[v][0] = { A[v],A[v] > 0 };
	for (auto u : g[v]) {
		if (u == p)continue;
		dfs(u, v);
		merge(v, u);
	}
}
signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N; cin >> N;
	rep(i, 0, N) { cin >> A[i]; }
	vector<int>U(N - 1), V(N - 1); rep(i, 0, N - 1) { cin >> U[i] >> V[i]; U[i]--, V[i]--; g[U[i]].eb(V[i]); g[V[i]].eb(U[i]); }
	dfs(0, -1);
	int ans = INF;
	rep(i, 0, sz[0]) {
		if (dp[0][i].first < 0 or dp[0][i].second)chmin(ans, i);
	}
	cout << ans << endl;



	return 0;
}
