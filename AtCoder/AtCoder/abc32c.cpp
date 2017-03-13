#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
#define DBG 0
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;

template <class InputIterator, class T, class BinaryOperation>
T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation binary_op) {
	while (first != last)
		init = binary_op(init, *first++);
	return init;
}

signed main() {
	int N, K; cin >> N >> K;
	vector<int>s(N), ans(1, 0);
	bool f(false);
	rep(i, 0, N) {
		cin >> s[i];
		if (s[i] == 0) {
			f = true;
		}
	}
	if (f) { cout << N << endl; return 0; }

	int l(0);
	int a(1);
	rep(i, 0, N) {
		a *= s[i];
		if (a <= K) {
			ans.push_back(i - l + 1);
		}
		else {
			while (a > K&&i != l) {
				a /= s[l];
				l++;
			}
		}
	}


	//rep(i, 0, N) {
	//	rep(j, i + 1, N + 1) {
	//		auto x = accumulate(s.begin() + i, s.begin() + j, 1LL, [](int init, int i) {return init*i; });
	//		dump(x);
	//		if (x <= K) {
	//			ans.push_back(j - i);
	//		}
	//	}
	//

	cout << *max_element(all(ans)) << endl;
	return 0;
}