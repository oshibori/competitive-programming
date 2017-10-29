#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
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
	vector<int> a(N), b(N); rep(i, 0, N) { cin >> a[i] >> b[i]; }
	map<int, int>m;
	rep(i, 0, N) {
		m[a[i]] += b[i];
	}
	vector<pair<int, int>>w;
	for (int i = 0; (1 << i) <= K; i++) {
		if (K&(1 << i)) {
			int k = K;
			k ^= (1 << i);
			k |= (1 << i) - 1;
			w.emplace_back(make_pair(k, 0));
		}
	}
	int index(0);
	while (K >= (1 << index + 1))index++;
	pair<int, int> ans2(0, 0), ans3(K, 0);
	dump(1 << index);
	for (auto &z : m) {

		if (z.first < (1 << index)) {
			dump(z);
			ans2.second += z.second;
			ans2.first |= z.first;
		}

		auto x = ans3;
		x.second += z.second;
		x.first |= z.first;
		if (ans3.first == x.first)ans3 = x;

		rep(i, 0, w.size()) {
			auto x = w[i];

			x.second += z.second;
			x.first |= z.first;
			if (x.first<=K)w[i] = x;
		}
	}

	pair<int, int>ans(0, 0);
	vector<pair<int, int>>v;
	for (auto &z : m) {
		v.emplace_back(make_pair(z.second, z.first));
	}
	sort(all(v), greater<pair<int, int>>());
	rep(i, 0, v.size()) {
		auto x = ans;
		x.second |= v[i].second;
		x.first += v[i].first;

		if (x.second <= K) {
			ans = x;
		}
	}
	int ans4(0);
	rep(i, 0, w.size()) {
		if (w[i].first <= K)chmax(ans4, w[i].second);
	}
	cout << max(max(ans3.second, max(ans.first, ans2.second)),ans4) << endl;
	return 0;
}