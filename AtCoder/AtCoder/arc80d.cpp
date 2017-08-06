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
	int H, W; cin >> H >> W;
	int N; cin >> N;
	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
	vector<vector<int>>v(H, vector<int>(W, -1));
	int k = 0, j = 0;
	bool r = true;
	rep(i, 0, N) {
		for (; a[i]; a[i]--) {
			v[k][j] = i + 1;

			if (r)j++;
			else j--;

			if (j == W) {
				k++;
				j--;
				r = false;
			}
			else if (j == -1) {
				k++;
				j++;
				r = true;
			}

		}
	}

	rep(i, 0, H)rep(j, 0, W) {
		cout << v[i][j] << (j == W - 1 ? '\n' : ' ');
	}

	return 0;
}










//#include "bits/stdc++.h"
//using namespace std;
//#ifdef _DEBUG
//#include "dump.hpp"
//#else
//#define dump(...)
//#endif
//
////#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//const double PI = acos(-1);
//const double EPS = 1e-9;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int H, W; cin >> H >> W;
//	int N; cin >> N;
//	vector<int> a(N); rep(i, 0, N) { cin >> a[i]; }
//	vector<vector<int>>v(H, vector<int>(W, -1));
//
//	auto within = [&](int x, int y) {
//		return 0 <= x&&x < H && 0 <= y&&y < W;
//	};
//	rep(i, 0, N) {
//		rep(j, 0, H)rep(k, 0, W) {
//			queue<tuple<int, int, int>>q;
//			q.push(make_tuple(j, k, i));
//			while (!q.empty()) {
//				auto u = q.front(); q.pop();
//
//				int x = get<0>(u), y = get<1>(u), z = get<2>(u);
//				if (!within(x, y))continue;
//				if (v[x][y] != -1)continue;
//				if (a[z] == 0)continue;
//
//				bool f = false;
//				rep(i, 0, 4) {
//					int X = x + dx[i], Y = y + dy[i];
//					if (!within(X, Y))continue;
//					if (v[X][Y] == z)f = true;
//				}
//				if (f) { v[x][y] = z; a[z]--; }
//
//				rep(i, 0, 4) {
//					int X = x + dx[i], Y = y + dy[i];
//					if (!within(X, Y))continue;
//					if (v[X][Y] != -1)continue;
//					if (a[z] == 0)continue;
//					q.push(make_tuple(X, Y, z));
//				}
//
//				rep(i, 0, H)rep(j, 0, W) {
//					cout << v[i][j] << (j == W - 1 ? '\n' : ' ');
//				}
//			}
//		}
//	}
//	rep(i, 0, H)rep(j, 0, W) {
//		cout << v[i][j] << (j == W - 1 ? '\n' : ' ');
//	}
//	return 0;
//}