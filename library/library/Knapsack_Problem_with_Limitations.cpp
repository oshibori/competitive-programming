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
	int N, W; cin >> N >> W;
	vector<int>v, w;
	rep(i, 0, N) {
		int a, b, c; cin >> a >> b >> c;
		int j(0);
		// 個数cを2進数(bit)で分解する
		// 分解後の成分の和のみで1からcまでの全ての整数を2進数で表現できるようにする
		// cから2^x++(0<=x)を順番に引いていくと、これ以上引けなくなる2^xに到達する
		// このとき分解後の成分の和は　a=0...00111...1111と
		// b=0...00BBB...BBBB(Bはどれか一つだけ1で残りは全て0である)
		// の和である(= c)
		// aの1になっているbitのon-offを自由に切り替えることによって
		// [0,a]の整数を自由に表現できる。
		// a+bでcを表現できるが([c])、このときcの2進数表現は
		// c=0...01000...011...1111なっている。
		// このときb以下の2^xは必ず一つずつ存在している。
		// よってそれらのbitを自由にon-offに切り替えることによって
		// [a+1,c)の整数を自由に表現できる
		// したがって[0,a],[a+1,c),[c]が表現できるので、
		// 整数cを2^x++(0<=x)で最小の要素数に分解することができると言える。

		while (c) {
			int x = min(c, (1 << j++));
			c -= x;
			v.emplace_back(x*a);
			w.emplace_back(x*b);
		}
	}
	vector<int>dp(W + 1, 0);
	rep(i, 0, v.size())rrep(j, w[i], W + 1)
		chmax(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W] << endl;
	return 0;
}