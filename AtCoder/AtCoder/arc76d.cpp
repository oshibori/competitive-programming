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

const int W(1), B(0);
vector<vector<pair<int, int>>>M; // dist,cost
int n;
int prim() {
	vector<int>d(n, INF), color(n, W);
	d[0] = 0;
	priority_queue<pair<int, int>>pq; // d[v], v
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		pair<int, int>f(pq.top()); pq.pop();
		dump(f.second);
		color[f.second] = B;
		if (d[f.second] < f.first*(-1)) continue;
		rep(i, 0, M[f.second].size()) {
			pair<int, int>u(M[f.second][i]);

			if (color[u.first] != B&&u.second < d[u.first]) {
				d[u.first] = u.second;
				pq.push(make_pair(d[u.first] * (-1), u.first));
			}
		}
	}
	return accumulate(all(d), 0);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	n = N;
	M = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
	vector<int> x(N), y(N); rep(i, 0, N) { cin >> x[i] >> y[i]; }
	vector<pair<int, int>>v;
	map<pair<int, int>, int>mp;
	rep(i, 0, N) {
		v.emplace_back(make_pair(x[i], y[i]));

	}
	sort(all(v), [](pair<int, int>&a, pair<int, int>&b) {return (a.first == b.first ? a.second < b.second : a.first < b.first); });
	v.erase(unique(all(v)), v.end());

	vector<pair<int, int>>h(v);
	sort(all(v), [](pair<int, int>a, pair<int, int>b) {return a.second < b.second; });
	sort(all(h), [](pair<int, int>a, pair<int, int>b) {return a.first < b.first; });
	v.erase(unique(all(v)), v.end());
	h.erase(unique(all(h)), h.end());
	rep(i, 0, v.size()) {
		mp[v[i]] = i;
	}
	N = v.size();
	n = v.size();
	dump(v, h);
	rep(i, 0, v.size()) {
		int x = mp[v[i]];
		if (i - 1 >= 0) {
			int c = abs(v[i].second - v[i - 1].second);
			int y = mp[v[i - 1]];
			M[x].emplace_back(make_pair(y, c));
		}
		if (i + 1 < N) {

			dump(i + 1);
			int c = abs(v[i + 1].second - v[i].second);
			int y = mp[v[i + 1]];
			M[x].emplace_back(make_pair(y, c));
		}

	}
	dump(111);
	rep(i, 0, N) {
		int x = mp[h[i]];
		if (i - 1 >= 0) {
			int c = abs(h[i].first - h[i - 1].first);
			int y = mp[h[i - 1]];
			M[x].emplace_back(make_pair(y, c));
		}
		if (i + 1 < N) {
			int c = abs(h[i + 1].first - h[i].first);
			int y = mp[h[i + 1]];
			M[x].emplace_back(make_pair(y, c));
		}

	}
	dump(222);
	cout << prim() << endl;
	return 0;
}