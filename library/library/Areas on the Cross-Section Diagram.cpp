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
	stack<int>s1;
	stack<pair<int, int>>s2;
	int sum(0); char ch;
	for (int i(0); cin >> ch; i++) {
		if (ch == '\\')s1.push(i);
		else if (ch == '/' && !s1.empty()) {
			int j = s1.top(); s1.pop();
			sum += i - j;
			int a = i - j;
			while (!s2.empty() && j < s2.top().first) {
				a += s2.top().second; s2.pop();
			}
			s2.push(make_pair(j, a));
		}
	}
	vector<int>ans;
	while (!s2.empty()) {
		ans.emplace_back(s2.top().second);
		s2.pop();
	}
	reverse(all(ans));
	cout << sum << endl;
	cout << ans.size();
	for (int i = 0; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}