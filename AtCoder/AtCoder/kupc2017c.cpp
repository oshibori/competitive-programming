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
	int A; cin >> A;
	string S; cin >> S;
	auto C = [&](char x) {return x - 'a' + 1; };
	auto C_inv = [&](int x) {return 'a' + x - 1; };
	string ans;
	vector<int>v(S.size());
	rep(i, 0, v.size())v[i] = C(S[i]);
	dump(v);
	rep(i, 0, v.size() - 1) {
		int x = min((26 - v[i]) / A, v[i + 1]);
		v[i] += x*A;
		v[i + 1] -= x;
	}
	string t;
	rep(i, 0, v.size()) {
		if (v[i] == 0)break;
		t.push_back(C_inv(v[i]));
	}
	ans = t;
	dump(S, ans);
	while (S != ans) {
		vector<int>v(ans.size());
		rep(i, 0, v.size())v[i] = C(ans[i]);
		dump(v);
		rep(i, 0, v.size() - 1) {
			int x = min((26 - v[i]) / A, v[i + 1]);
			v[i] += x*A;
			v[i + 1] -= x;
		}
		string t;
		rep(i, 0, v.size()) {
			if (v[i] == 0)break;
			t.push_back(C_inv(v[i]));
		}
		S = ans;
		ans = t;
		dump(S);
		dump(ans);
	}
	cout << ans << endl;

	return 0;
}