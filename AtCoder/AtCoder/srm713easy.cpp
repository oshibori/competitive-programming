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

class SymmetryDetection {
public:
	string detect(vector <string> board) {
		int n = board.size(), m = board[0].size();
		// odd (n-1)/2, even (n/2)
		bool n_f = true, m_f = true;
		vector<string>h(board),v(board);
		
		rep(i, 0, n) {
			reverse(all(h[i]));
		}
		rep(i, 0, n) {
			if (board[i] != h[i])n_f = false;
		}

		rep(i, 0, n)rep(j, 0, m) {
			v[n - 1 - i][j] = board[i][j];
		}

		rep(i, 0, n) {
			if (board[i] != v[i])m_f = false;
		}

		string ans;

		if (n_f&&m_f)ans = "Both";
		else if (n_f)ans = "Vertically symmetric";
		else if (m_f)ans = "Horizontally symmetric";
		else ans = "Neither";

		return ans;
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<string> v;
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	cout << SymmetryDetection().detect(v) << endl;
	return 0;
}