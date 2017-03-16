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
int cntdiff(string a, string b) {
	int ret(0);
	int n = min(a.size(), b.size());
	rep(i, 0, n)ret += a[i] != b[i];
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	string s; cin >> s;
	string ans;
	vector<int>list(256, 0);
	rep(i, 0, N)list[s[i]]++;

	for (int i = 0; i < N; i++) {
		//string current(s);
		//swap(s[i], *min_element(s.begin() + i, s.end()));
		string t;
		vector<int>list2(list);
		rep(j, 0, ans.size())list2[ans[j]]--;
		dump(list2);
		rep(j, 0, N) {
			list2[s[j]]--;
			if (list2[s[j]] >= 0) {
				t.push_back(s[j]);
			}
		}
		sort(all(t));
		dump(t);

		rep(j, 0, t.size()) {
			string x = ans + t[j], y;
			if (x.size() == s.size()) {
				ans = x;
				continue;
			}
			rep(k, 0, t.size())if (k != j)y.push_back(t[k]);

			dump(x); dump(y);

			string z = s.substr(i + 1);
			dump(z);
			rep(k, 0, y.size()) {
				if (z[k] != y[k]) {
					
					rep(g, 0, y.size()) {
						if (z[k] == y[g] && y[g] != z[g])swap(y[k], y[g]);
					}



					//auto w = find(y.begin(), y.end(), z[k]);
					//if (w != y.end() && *w != z[distance(y.begin(), w)]) {
					//	swap(y[k], *w);
					//}

				}
				dump(y);
			}
			dump(y);
			dump(x + y);
			dump(cntdiff(x + y, s));
			if (cntdiff(x + y, s) <= K) {
				ans.push_back(t[j]);
				break;
			}
		}
		dump(ans);

		//if (cntdiff(ans, s) > K)s = current;
	}
	cout << ans << endl;
	return 0;
}