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
class  MaximumRangeDiv2 {
public:
	int findMax(string s) {
		int L(-INF), S(INF);
		int ret(0);
		ret = count(all(s), '+') - count(all(s), '-');
		rep(i, 0, s.size()) {
			vector<int>ans; ans.emplace_back(0);
			int v(0);
			rep(j, 0, s.size()) {
				if (s[j] == '+')v++;
				else v--;
				ans.emplace_back(v);
				if (i == j) {
					if (s[j] == '+') {
						v -= 2;
						ans.emplace_back(v);
					}
					else {
						v += 2;
						ans.emplace_back(v);
					}
				}

			}
			dump(ans);
			int a = *max_element(all(ans));
			int b = *min_element(all(ans));
			chmax(ret, abs(a - b));
		}
		return ret;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	cout << MaximumRangeDiv2().findMax(s) << endl;
	return 0;
}