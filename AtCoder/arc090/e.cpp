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
template <int MOD> struct ModInt {
	static const int Mod = MOD;
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
template <int MOD> ostream &operator<<(ostream &os, const ModInt<MOD> &m) {
	return os << m.x;
}
template <int MOD> istream &operator>>(istream &is, ModInt<MOD> &m) {
	signed long long s;
	is >> s;
	m = ModInt<MOD>(s);
	return is;
};
// pow(mint(2), 1000) のように
template <int MOD> ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1)
			r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

//#define int long long を使っても大丈夫
using mint = ModInt<1000000007>;

// nCrで用いる
vector<mint> fact, factinv;
// nCrで用いる 予め計算しておく
void nCr_compute_factinv(int N) {
	N = min(N, mint::Mod - 1);
	fact.resize(N + 1);
	factinv.resize(N + 1);
	fact[0] = 1;
	rep(i, 1, N + 1) fact[i] = fact[i - 1] * i;
	factinv[N] = fact[N].inverse();
	for (int i = N; i >= 1; i--)
		factinv[i - 1] = factinv[i] * i;
}
mint nCr(int n, int r) {
	if (n >= mint::Mod)
		return nCr(n % mint::Mod, r % mint::Mod) *
		nCr(n / mint::Mod, r / mint::Mod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

mint nHr(int n, int r) { return r == 0 ? 1 : nCr(n + r - 1, r); }

using Weight = int;
using Flow = int;
struct Edge {
	int s, d; Weight w; Flow c;
	Edge() {};
	Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<pair<Weight, mint>>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}
//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
using P = pair<Weight, mint>;
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
	int n = g.size();
	assert(s < n);
	enum { WHITE, GRAY, BLACK };
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n);
	dist.assign(n, make_pair(INF, 0)); dist[s] = P(0, 1);
	using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
		if (dist[v].first < d)continue;
		//dump(v,dist);
		color[v] = BLACK; prev[v]=(u);
		for (auto &e : g[v]) {
			if (color[e.d] == BLACK)continue;
			if (dist[e.d].first > dist[v].first + e.w) {
				dist[e.d].first = dist[v].first + e.w;
				dist[e.d].second = dist[v].second;
				pq.emplace(dist[e.d].first, e.d, v);
				color[e.d] = GRAY;
			}
			else if (dist[e.d].first == dist[v].first + e.w) {
				dist[e.d].second += dist[v].second;
			}
		}
	}
	return prev;
}

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, M; cin >> N >> M;
	int S, T; cin >> S >> T; S--, T--;
	Graph g(N);

	vector<int>U(M), V(M), D(M); rep(i, 0, M) {
		cin >> U[i] >> V[i] >> D[i]; U[i]--, V[i]--;
		addEdge(g, U[i], V[i], D[i]);
	}
	Array from_s, from_t;
	auto prev=dijkstra(g, S, from_s);
	dump(prev);
	dijkstra(g, T, from_t);
	dump(from_s);
	dump(from_t);
	mint ans = from_s[T].second*from_t[S].second;
	dump(ans);
	rep(i, 0, N) {
		if (from_s[i].first == from_t[i].first) {
			dump(i);
			mint hoge=from_s[i].second*from_t[i].second;
			ans -= hoge * hoge;
		}
	}
	dump(ans);
	rep(i, 0, N) {
		for (auto e : g[i]) {
			if (from_s[i].first + e.w +from_t[e.d].first==from_s[T].first) {
				dump(i, e.d);
				int a = max(from_s[i].first, from_t[e.d].first);
				int b = min(from_s[i].first + e.w, from_t[e.d].first + e.w);


				if (a < b) {
					mint hoge = from_s[i].second*from_t[e.d].second;
					ans -= hoge * hoge;
				}

			}
		}
	}
	cout << ans << endl;
	return 0;
}
