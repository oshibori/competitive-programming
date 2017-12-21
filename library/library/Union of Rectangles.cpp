#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
vector<T> compress(vector<T>&a, vector<T>&b) {
	// ç¿ïWà≥èk
	vector<T>ret;
	ret.insert(ret.end(), all(a));
	ret.insert(ret.end(), all(b));
	sort(all(ret));
	ret.erase(unique(all(ret)), ret.end());
	rep(i, 0, a.size())a[i] = distance(ret.begin(), lower_bound(all(ret), a[i]));
	rep(i, 0, b.size())b[i] = distance(ret.begin(), lower_bound(all(ret), b[i]));
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int>x1(N), y1(N), x2(N), y2(N);
	rep(i, 0, N)cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	auto zipx = compress(x1, x2), zipy = compress(y1, y2);
	vector<vector<int>>field(zipx.size(), vector<int>(zipy.size(), 0));
	rep(i, 0, N) {
		field[x1[i]][y1[i]]++;
		field[x2[i]][y2[i]]++;
		field[x1[i]][y2[i]]--;
		field[x2[i]][y1[i]]--;
	}
	rep(i, 0, zipx.size())rep(j, 1, zipy.size())field[i][j] += field[i][j - 1];
	rep(i, 0, zipy.size())rep(j, 1, zipx.size())field[j][i] += field[j - 1][i];
	int ans(0);
	rep(i, 0, zipx.size() - 1)rep(j, 0, zipy.size() - 1) {
		if (field[i][j])ans += (zipx[i + 1] - zipx[i])*(zipy[j + 1] - zipy[j]);
	}
	cout << ans << endl;
	return 0;
}