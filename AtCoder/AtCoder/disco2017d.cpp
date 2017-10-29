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
	int A, B; cin >> A >> B;
	vector<string>m(H);
	rep(i, 0, H)cin >> m[i];

	int ans(0);
	int stone(0);
	rep(i, 0, H)rep(j, 0, W)if (m[i][j] == 'S')stone++;

	int w = W / 2, h = H / 2;
	int x(0), y(0), z(0);
	rep(i, 0, H)rep(j, 0, H) {
		// (i,j),(h-i-1,j) ,(i,w-j-1),(h-i-1,w-j-1)
		if (m[i][j] == 'S') {
			bool a = m[H - i - 1][j] == 'S';
			bool b = m[i][W - j - 1] == 'S';
			bool c = m[H - i - 1][W-j-1] == 'S';

			if (a&&b&&c) {
				x++;
			}
			if (a)y++;
			if (b)z++;
		}
	}
	dump(x, y, z);
	x /= 4;
	y /= 2;
	z /= 2;
	y++;
	z++;
	
	ans = A + B;

	cout << ans << endl;

	return 0;
}