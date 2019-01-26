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
// äOÇ≈MODÇåàÇﬂÇÈÅiMODÇ™ïœêî)----------------------------------------------
int MOD;
struct ModInt {
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) {
		int sigt = sig % MOD;
		if (sigt < 0)
			sigt += MOD;
		x = sigt;
	}
	ModInt(signed long long sig) {
		int sigt = sig % MOD;
		if (sigt < 0)
			sigt += MOD;
		x = sigt;
	}
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) {
		if ((x += that.x) >= MOD)
			x -= MOD;
		return *this;
	}
	ModInt &operator-=(ModInt that) {
		if ((x += MOD - that.x) >= MOD)
			x -= MOD;
		return *this;
	}
	ModInt &operator*=(ModInt that) {
		x = (unsigned long long)x * that.x % MOD;
		return *this;
	}
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b;
			std::swap(a, b);
			u -= t * v;
			std::swap(u, v);
		}
		if (u < 0)
			u += MOD;
		ModInt res;
		res.x = (unsigned)u;
		return res;
	}
};
ostream &operator<<(ostream &os, const ModInt &m) { return os << m.x; }
istream &operator>>(istream &is, ModInt &m) {
	signed long long s;
	is >> s;
	m = ModInt(s);
	return is;
};
// pow(mint(2), 1000) ÇÃÇÊÇ§Ç…
ModInt pow(ModInt a, unsigned long long k) {
	ModInt r = 1;
	while (k) {
		if (k & 1)
			r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
//---------------------------------------------------------------------
using mint = ModInt;
vector<int>g[101010];
mint dp[101010], ans[101010];
mint dfs(int v, int p) {
	mint ret = 1;
	for (auto u : g[v]) {
		if (u == p)continue;
		ret *= dfs(u, v) + 1;
	}
	return dp[v] = ret;
}
void dfs2(int v, int p, mint d) {
	mint ret = 1;
	vector<mint>l;
	for (auto u : g[v]) {
		if (u != p) {
			ret *= dp[u] + 1;
			l.eb(dp[u] + 1);
		}
		else {
			ret *= d + 1;
			l.eb(d + 1);
		}
	}
	vector<mint>r(l);
	rep(i, 1, l.size())l[i] *= l[i - 1];
	rrep(i, 1, r.size())r[i - 1] *= r[i];
	ans[v] = ret;
	rep(i,0,g[v].size()) {
		int u = g[v][i];
		if (u == p)continue;
		mint x = 1;
		if (i > 0)x *= l[i - 1];
		if (i + 1 < r.size())x *= r[i + 1];
		dfs2(u, v, x);
	}

}
signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, M; cin >> N >> M;
	MOD = M;
	loop(N - 1) {
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].eb(b);
		g[b].eb(a);
	}
	dfs(0, -1);
	dfs2(0, -1, 0);
	rep(i, 0, N) {
		cout << ans[i] << endl;
	}

	return 0;
}
