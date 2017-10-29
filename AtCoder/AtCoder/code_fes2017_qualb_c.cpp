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

void bfs(vector<vector<int>>&G, int s) {
	queue<pair<int, int>>q;

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<set<int>>G1(N, set<int>());
	vector<set<int>>G2(N, set<int>());
	rep(i, 0, N)G1[i].insert(i);
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		a--, b--;
		G1[a].insert(b);
		G1[b].insert(a);
	}
	bool f(false);
	int ans(0);
	rep(j, 0, 10) {
		rep(i, 0, N) {
			queue<pair<pair<int, int>, int>>q;
			// d,c,prev
			q.push(make_pair(make_pair(i, 0), -1));
			while (q.size()) {
				auto u = q.front(); q.pop();

				if (u.first.second == 3) {
					if (G1[i].count(u.first.first))continue;

					G1[i].insert(u.first.first);
					ans++;
					u.first.second = 1;
				}

				for (auto v : G1[u.first.first]) {
					if (v == u.first.first)continue;
					q.push(make_pair(make_pair(v, u.first.second + 1), u.first.first));
				}
			}

		}
	}

	cout << ans / 2 << endl;
	return 0;
}