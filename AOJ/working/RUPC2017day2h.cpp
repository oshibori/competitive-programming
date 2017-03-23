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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
class Gear {
public:
	long long x, y;
	Gear(long long x, long long y) :x(x), y(y) {}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, A, B; cin >> N >> A >> B;
	vector<vector<Gear>>G(5, vector<Gear>(1, Gear(0, 0)));
	vector<int>max_x, max_y, min_x, min_y;
	vector<vector<int>>M_x(5),M_y(5);
	rep(i, 0, N) {
		int t, x, y; cin >> t >> x >> y; t--;
		G[t].emplace_back(Gear(x, y));
		M_x[t].emplace_back(x);
		M_y[t].emplace_back(y);
	}
	rep(i, 0, 5) {
		max_x.emplace_back(*max_element(all(M_x[i])));
		min_x.emplace_back(*min_element(all(M_x[i])));
		max_y.emplace_back(*max_element(all(M_y[i])));
		min_x.emplace_back(*min_element(all(M_y[i])));
	}

	rep(i, 0, 5) {
		sort(all(G[i]), [](const Gear &x, const Gear &y) {
			return x.x < y.x;
		});
	}

	
	//map<tuple<int, int, int>, bool>mp;

	//function<bool(int, int, int)> dfs = [&](int i, int x, int y) {
	//	if (i == 5) return A <= x &&x <= B&&A <= y &&y <= B;

	//	if (mp.count(tuple<int, int, int>(i, x, y)))return mp[tuple<int, int, int>(i, x, y)];

	//	bool f(false);
	//	rep(j, 0, G[i].size()) {
	//		//if (A <= x + G[i][j].x&&x + G[i][j].x <= B&&A <= y + G[i][j].y&&y + G[i][j].y <= B)
	//		if(0<=i&&i<=2)chmax(f, dfs(i + 1, x + G[i][j].x, y + G[i][j].y));
	//		else if (i == 3) {

	//		}
	//		if (f)break;
	//	}
	//	return mp[tuple<int, int, int>(i, x, y)] = f;

	//};
	//
	//cout << (dfs(0, 0, 0) ? "Yes" : "No") << endl;

	return 0;
}
