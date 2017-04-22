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
	long long H, W, N; cin >> H >> W >> N;
	vector<int> a(N), b(N); rep(i, 0, N) { cin >> a[i] >> b[i]; }
	map<pair<int, int>, int >mp;
	int dx[] = { 1,1,0,-1,-1,-1,0,1 }, dy[] = { 0,1,1,1,0,-1,-1,-1 };
	rep(i, 0, N) {
		mp[make_pair(--a[i],--b[i])]++;
		rep(j, 0, 8) {
			int x = a[i] + dx[j], y = b[i] + dy[j];
			mp[make_pair(x, y)]++;
		}
	}
	vector<long long>v(10, 0); v[0] = (H - 2)*(W - 2);
	for (auto &e : mp) {
		if (1 <= e.first.first&&e.first.first <= (H - 2) && 1 <= e.first.second&&e.first.second <= (W - 2)) {
			v[0]--;
			v[e.second]++;
		}
	}
	rep(i, 0, 10)cout << v[i] << endl;
	return 0;
}