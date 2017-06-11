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
class  ImageCompression {
public:
	string isPossible(vector <string> image, int k) {
		int n = image.size();
		int m = image[0].length();
		auto check = [&](int x, int y) {
			int c = image[x][y];
			rep(i, x, x + k) {
				rep(j, y, y + k) {
					if (c != image[i][j]) {
						return false;
					}
				}
			}
			return true;
		};
		for (int i = 0; i < n; i += k) {
			for (int j = 0; j < m; j += k) {
				if (check(i, j) == false) {
					return "Impossible";
				}
			}
		}
		return "Possible";
	}
	
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	int k; cin >> k;
	vector<string>v(N);
	rep(i, 0, N)cin >> v[i];
	cout << ImageCompression().isPossible(v,k) << endl;
	return 0;
}