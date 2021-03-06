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
	string s; cin >> s;
	rep(i, 0, s.size()) {
		switch (s[i]) {
		case 'O':s[i] = '0'; break;
		case 'D':s[i] = '0'; break;
		case 'I':s[i] = '1'; break;
		case 'Z':s[i] = '2'; break;
		case 'S':s[i] = '5'; break;
		case 'B':s[i] = '8'; break;
		default:break;
		}
	}
	cout << s << endl;

	return 0;
}