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
template <class Abel> struct BIT {
	vector<Abel> dat;
	Abel UNITY_SUM = 0; // to be set

	/* [1, n] */
	BIT(int n) { init(n); }
	void init(int n) {
		dat.resize(n + 1);
		for (int i = 0; i < (int)dat.size(); ++i)
			dat[i] = UNITY_SUM;
	}

	/* a is 1-indexed */
	inline void add(int a, Abel x) {
		for (int i = a; i < (int)dat.size(); i += i & -i)
			dat[i] = dat[i] + x;
	}

	/* [1, a], a is 1-indexed */
	inline Abel sum(int a) {
		Abel res = UNITY_SUM;
		for (int i = a; i > 0; i -= i & -i)
			res = res + dat[i];
		return res;
	}

	/* [a, b), a and b are 1-indexed */
	inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

	/* k-th number (k is 0-indexed) */
	int get(long long k) {
		++k;
		int res = 0;
		int N = 1;
		while (N < (int)dat.size())
			N *= 2;
		for (int i = N / 2; i > 0; i /= 2) {
			if (res + i < (int)dat.size() && dat[res + i] < k) {
				k = k - dat[res + i];
				res = res + i;
			}
		}
		return res + 1;
	}
};

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int N, M; cin >> N >> M;
	vector<int>l(N), r(N); rep(i, 0, N) { cin >> l[i] >> r[i]; }
	vector<vector<int>>d(M + 1);
	rep(i, 0, N) {
		d[r[i] - l[i] + 1].eb(i);
	}
	BIT<int> bit(M + 10);
	int remain = N;
	rep(i, 1, M + 1) {
		int ans = remain;
		for (int j = 0; j < M + 1; j += i) {
			ans += bit.sum(j);
		}
		cout << ans << endl;
		remain -= d[i].size();
		for (int j : d[i]) {
			bit.add(l[j], 1);
			bit.add(r[j] + 1, -1);
		}
	}

	return 0;
}
