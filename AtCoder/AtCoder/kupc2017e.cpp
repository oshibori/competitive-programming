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
	int N, M; cin >> N >> M;
	vector<int> v(N); rep(i, 0, N) { cin >> v[i]; }
	auto key = [&](int x) {return N + x; };
	auto jewellery = [&](int x) {return x; };
	vector<vector<int>>G(N + M);
	rep(i, 0, M) {
		int x, y; cin >> x >> y;
		x--, y--;
		G[key(i)].emplace_back(jewellery(x));
		G[key(i)].emplace_back(jewellery(y));
		G[jewellery(x)].emplace_back(key(i));
		G[jewellery(y)].emplace_back(key(i));

	}
	vector<int>colors(N + M, -1);
	int c(0);

	rep(i, 0, N + M) {
		if (colors[i] != -1)continue;

		queue<int>q;
		q.push(i);
		while (q.size()) {
			int u = q.front(); q.pop();
			if (colors[u] != -1)continue;
			colors[u] = c;

			rep(j, 0, G[u].size()) {
				q.push(G[u][j]);
			}
		}
		c++;
	}

	vector<pair<vector<int>, int>>connected(c);
	rep(i, 0, N) {
		connected[colors[i]].first.emplace_back(v[i]);
	}
	rep(i, 0, M) {
		connected[colors[key(i)]].second++;
	}

	int ans(0);
	rep(i, 0, c) {
		sort(all(connected[i].first),greater<int>());

		ans += accumulate(connected[i].first.begin(), connected[i].first.begin() + connected[i].second, 0ll);

	}

	cout << ans << endl;

	return 0;
}