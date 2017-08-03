#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	string s; cin >> s;
	map<char, int>m;
	int cnt(0);
	vector<vector<int>>table(26);
	vector<int>v(N + 1, 0);
	dump(1);
	rep(i, 0, N) {
		table[s[i] - 'A'].push_back(i);
	}
	dump(2);
	rep(i, 0, 26) {
		dump(table[i].empty());
		if (table[i].empty())continue;
		v[table[i][0]]++;
		v[table[i].back() + 1]--;
	}
	dump(3);
	rep(i, 1, v.size())v[i] += v[i - 1];
	bool f(true);
	rep(i, 0, v.size()) {
		if (v[i] > K)f = false;
	}
	if (f)cout << "NO" << endl;
	else cout << "YES" << endl;

	dump(v);
	return 0;
}