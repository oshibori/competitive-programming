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
	int N, C; cin >> N >> C;
	vector<int> L(N); rep(i, 0, N) { cin >> L[i]; }
	int l = 0;
	int r = N - 1;
	int ans(0);
	
	sort(all(L));
	dump(L);

	while (l <= r) {
		dump(l, r);
		if (l != r) {
			if (L[l] + L[r] + 1 <= C) {
				ans++;
				l++;
				r--;
			}
			else {
				r--;
				ans++;
			}
		}
		else {
			ans++;
			l++;
			r--;
		}
	}
	cout << ans << endl;
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
//#define int long long
//#define rep(i,a,b) for(int i=(a);i<(b);i++)
//#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
//#define all(c) begin(c),end(c)
//const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
//const int MOD = (int)(1e9) + 7;
//const double PI = acos(-1);
//const double EPS = 1e-9;
//template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
//template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
//
//signed main() {
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	int N, C; cin >> N >> C;
//	vector<int> L(N + 1, 0); rep(i, 1, N + 1) { cin >> L[i]; }
//	L.push_back(INF);
//	sort(all(L));
//	int ans(0);
//	vector<bool>v(N+1+1, false);
//	dump(L);
//	rep(i, 1, N+1) {
//		dump(i);
//		dump(v);
//		// 0< b <= C -a -1
//		if (v[i] == true)continue;
//		v[i] = true;
//		int x = C - L[i] - 1;
//		auto y = lower_bound(all(L), x);
//		int index = distance(L.begin(), y);
//		dump(x, *y, index);
//		while ((0<index)&&(v[index]==false)&&(L[index]>C-L[i]-1)) {
//			dump(index);
//			index--;
//		}
//		if (index != 0)v[index] = true;
//		ans++;
//
//	}
//	cout << ans << endl;
//	return 0;
//}