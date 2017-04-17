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
bool check(string s) {
	bool f(true);
	rep(i, 0, s.size())if (s[i] == '-')f = false;
	return f;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	rep(i, 0, T) {
		string s; cin >> s;
		int K; cin >> K;
		priority_queue<pair<int, string>>q;
		q.push(make_pair(0, s));
		map<string, int>mp;
		int ans(INF);
		while (!q.empty()) {
			auto u = q.top(); q.pop();
			if (mp.count(u.second))continue;
			else mp[u.second] = -u.first;

			if (check(u.second)) {
				ans = -u.first;
				break;
			}
			
			for (int i(0); i + K - 1 < s.size();i++) {
				string t(u.second);
				rep(j, i, i + K) {
					if (u.second[j] == '+')t[j] = '-';
					else t[j] = '+';
				}
				q.push(make_pair(u.first - 1, t));
			}

		}
		string o;
		if (ans == INF)o = "IMPOSSIBLE";
		else o = to_string(ans);
		cout << "Case #" << i + 1 << ": " << o << endl;

		

	}
	return 0;
}