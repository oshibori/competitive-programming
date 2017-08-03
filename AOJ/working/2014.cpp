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
vector<vector<int>>v_w, v_b;
vector<string>field;
int dx[] = { 1,0,-1,0 }, dy[] = { 0, 1, 0, -1 };
bool within(int x, int y) {
	return 0 <= x&&x < field.size() && 0 <= y&&y < field[0].size();
}
void color(int x, int y, char c, vector<vector<int>>&a) {
	if (a[x][y] != 0)return;
	a[x][y] = (c == 'W' ? 1 : -1);
	rep(i, 0, 4) {
		int X = x + dx[i], Y = y + dy[i];
		if (within(X, Y) && field[X][Y] == '.')color(X, Y, c, a);
	}


}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w, h;
	while (cin >> w >> h, w&&h) {
		field = vector<string>(h);
		rep(i, 0, h)cin >> field[i];
		int cnt_w(0), cnt_b(0);
		rep(i, 0, h)rep(j, 0, w) {
			if (field[i][j] == 'W')cnt_w++;
			else if (field[i][j] == 'B')cnt_b++;

		}
		v_w = v_b = vector<vector<int>>(h, vector<int>(w, 0));
		dump(cnt_w, cnt_b);
		rep(i, 0, h)rep(j, 0, w) {
			if (field[i][j] == 'W') {
				rep(k, 0, 4) {
					int a = i + dx[k], b = j + dy[k];
					if (within(a, b)&&field[a][b]=='.')color(a, b, 'W', v_w);
				}
			}
			else if (field[i][j] == 'B') {
				rep(k, 0, 4) {
					int a = i + dx[k], b = j + dy[k];
					if (within(a, b)&&field[a][b]=='.')color(a, b, 'B', v_b);
				}
			}
		}
		int result_w(0), result_b(0);
		rep(i, 0, h)rep(j, 0, w) {
			if (v_w[i][j] == 1 && v_b[i][j] == -1)continue;
			else if (v_w[i][j] == 1)result_w++;
			else if (v_b[i][j] == -1)result_b++;
		}
		cout << result_b << " " << result_w << endl;

	}
	return 0;
}