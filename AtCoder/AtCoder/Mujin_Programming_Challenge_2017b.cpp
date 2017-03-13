#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;
int n;
int check(const vector<string> &v) {
	int a(0);
	rep(i, 0, n)rep(j, 0, n)if (v[i][j] == '#')a++;
	return a;
}
vector<int> horizontalcnt(const vector<string> &vec) {
	vector<int>w;
	rep(i, 0, n) {
		int c(0);
		rep(j, 0, n)if (vec[i][j] == '#')c++;
		w.push_back(c);
	}
	return w;
}
vector<int> virticalcnt(const vector<string> &vec) {
	vector<int>w;
	rep(i, 0, n) {
		int c(0);
		rep(j, 0, n)if (vec[j][i] == '#')c++;
		w.push_back(c);
	}
	return w;
}

vector<string> next(vector<string>v, int x, int y) {
	string s(v[x]);
	rep(i, 0, n) {
		v[i][y] = s[i];
	}
	return v;
}
int bfs(vector<string>v) {
	queue<pair<vector<string>, int>>q;
	q.push(make_pair(v, 0));
	while (!q.empty()) {
		auto g = q.front(); q.pop();
		if (check(g.first) == n*n)return g.second;
		rep(i, 0, n) {
			rep(j, 0, n) {
				auto h = next(g.first, i, j);
				auto d = check(h);

				if (d < g.second)continue;
				else if (g.second >= 6)continue;
				q.push(make_pair(h, g.second + 1));
			}
		}
	}
	return -1;
}
signed main() {
	vector<string>vec;
	cin >> n;
	vec = vector<string>(n); rep(i, 0, n)cin >> vec[i];
	
	int c(0);
	rep(i, 0, n) {
		bool f(false);
		rep(j, 0, n) {
			if (vec[j][i] == '.')f = true;
		}
		c += f;
	}
	int k(INF);
	rep(i, 0, n) {
		int x = count(all(vec[i]), '.');
		bool f(false);
		rep(j, 0, n) {
			if (vec[j][i] == '#')f = true;
		}
		if (f)k = min(k, x);
		else k = min(k, x + 1);
	}

	int cnt(0);
	rep(i, 0, n)rep(j, 0, n)if (vec[i][j] == '#')cnt++;
	if (cnt == 0)cout << -1 << endl;
	else cout << c + k << endl;




	//if (n == 2) {
	//	if (cnt == 0)cout << -1 << endl;
	//	else if (cnt == 4)cout << 0 << endl;
	//	else if (cnt == 3)cout << 1 << endl;
	//	else if ((vec[0][0] == '#' && (vec[0][1] == '#' || vec[1][0] == '#')) || (vec[1][1] == '#' && (vec[0][1] == '#' || vec[1][0] == '#')))cout << 2 << endl;
	//	else if (vec[0][0] == '#' || vec[1][1] == '#')cout << 3 << endl;
	//}
	//else if (n == 3) {
	//	auto a = horizontalcnt();
	//	auto b = virticalcnt();
	//	if (*max_element(all(a)) == n) {
	//		cout << n - count(all(b), n) << endl;
	//	}
	//	else if (*max_element(all(a)) == 1) {
	//		cout << 5 - count(all(b), n) << endl;
	//	}
	//	else if (*max_element(all(a)) == 2) {
	//		cout << dfs(vec, 0) << endl;
	//	}

	//}
	return 0;
}