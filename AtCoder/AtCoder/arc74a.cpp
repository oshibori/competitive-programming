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
	auto x = [&](int s, int t, int u) {
		return max(s, max(t, u)) - min(s, min(t, u));
	};
	int H, W; cin >> H >> W;
	int ans(INF);
	rep(i, 1, H - 1) {
		int a = i*W;
		int h = (H - i) / 2;
		int h2 = (H - i) - h;
		int b = h*W, c = h2*W;
		chmin(ans, x(a, b, c));
	}
	rep(i, 1, H) {
		int a = i*W;
		int b = (H - i)*(W / 2);
		int c = (H - i)*(W - W / 2);
		chmin(ans, x(a, b, c));
	}
	swap(H, W);
	rep(i, 1, H - 1) {
		int a = i*W;
		int h = (H - i) / 2;
		int h2 = (H - i) - h;
		int b = h*W, c = h2*W;
		chmin(ans, x(a, b, c));
	}
	rep(i, 1, H) {
		int a = i*W;
		int b = (H - i)*(W / 2);
		int c = (H - i)*(W - W / 2);
		chmin(ans, x(a, b, c));
	}
	cout << ans << endl;
	//if (H % 3 == 0 || W % 3 == 0)cout << 0 << endl;
	//else if (W == 2 && H == 2)cout << 1 << endl;
	//else {
	//	if (W % 3 == 1 && H % 3 == 1) {
	//		int n = W / 3, m = H / 3;
	//		int a = n*H, b = 2 * m*(n + n + 1), c = (m + 1)*(n + n + 1);
	//		cout << x(a, b, c) << endl;

	//	}
	//	else if (W % 3 == 1 && H % 3 == 2 || H % 3 == 1 && W % 3 == 2) {
	//		if (H % 3 == 1 && W % 3 == 2)swap(H, W);
	//		int n = W / 3, m = H / 3;
	//		int a = m*W, b = 2 * (m + 1)*H / 2, c = b;
	//		cout << x(a, b, c) << endl;
	//	}
	//	else {
	//		int n = W / 3, m = H / 3;
	//		int a = n*H, b = (2 * m + 1)*(n + 1) * 2, c = (m + 1)*(n + 1) * 2;
	//		cout << x(a, b, c) << endl;
	//	}
		//int ans(INF);
		////1

		//int h(H), w(W), a, b, c;
		//a = h / 3 * w; h -= h / 3; b = h / 2 * w; c = (h - h / 2)*w;
		//chmin(ans, x(a, b, c));
		//dump(a, b, c, ans);
		////2
		//h = H, w = W;
		//a = w / 3 * h; w -= w / 3; b = w / 2 * h; c = (w - w / 2)*h;
		//chmin(ans, x(a, b, c));
		//dump(a, b, c, ans);
		////3
		//h = H, w = W;
		//a = (w + 2) / 3 * h; w -= (w + 2) / 3; b = h / 2 * w; c = (h - h / 2)*w;
		//chmin(ans, x(a, b, c));
		//dump(a, b, c, ans);
		////4
		//h = H, w = W;
		//a = (h + 2) / 3 * w; h -= (h + 2) / 3; b = w / 2 * h; c = (w - w / 2)*h;
		//chmin(ans, x(a, b, c));
		//dump(a, b, c, ans);

		//cout << ans << endl;
//}

	return 0;
}