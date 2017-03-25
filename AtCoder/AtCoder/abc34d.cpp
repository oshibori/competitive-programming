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
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
class Cup {
public:
	double solt, weight, concentration;
	Cup() {};
	Cup(double w, double p, double s) :weight(w), concentration(p), solt(s) {};
	bool operator<(const Cup &other) { return concentration < other.concentration; }
	Cup operator+(Cup other)const {
		Cup ret;
		ret.weight = this->weight + other.weight;
		ret.solt = this->solt + other.solt;
		ret.concentration = ret.solt / ret.weight;
		return ret;
	}
};
ostream &operator<<(ostream &os, const Cup &c) {
	return (os << c.weight << " " << c.solt << " " << c.concentration);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int K, N; cin >> N >> K;
	vector<double>w(N), p(N);
	rep(i, 0, N)cin >> w[i] >> p[i];
	double l = 0.0, r = 110.0;
	while (r - l > EPS) {
		double mid = (l + r) / 2;

		vector<double>y(N);
		rep(j, 0, N)y[j] = w[j] * (p[j] - mid);
		sort(all(y), greater<double>());

		if (accumulate(y.begin(), y.begin() + K, 0.0) - 0 >= EPS)l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(8) << l << endl;


	//vector<vector<Cup>>dp(N + 1, vector<Cup>(N + 1, Cup(0, 0, 0)));
	//rep(i, 0, N)rep(j, 0, i + 1) {
	//	chmax(dp[i + 1][j], dp[i][j]);
	//	chmax(dp[i + 1][j + 1], dp[i][j] + c[i + 1]);
	//}
	//cout << dp[N][K].concentration*100 << endl;

	return 0;
}