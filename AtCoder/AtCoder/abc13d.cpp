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

	int N, M, D; cin >> N >> M >> D;
	vector<int>v(N); rep(i, 0, N)v[i] = i;
	dump(v);
	rep(i, 0, M) {
		int A; cin >> A; A--;
		swap(v[A], v[A + 1]);
		dump(v);
	}
	vector<int>b(N); rep(i, 0, N)b[v[i]] = i;
	v = b;
	dump(v);
	
	vector<bool>used(N, false);
	vector<int>roop(N);
	rep(i, 0, N) {
		vector<int>t;
		if (!used[i]) {
			int x(i);
			t.emplace_back(x);
			used[x] = true;
			x = v[x];
			while(x != i) {
				used[x] = true;
				t.emplace_back(x);
				x = v[x];
			}
			int s = t.size();
			rep(j, 0, s)roop[t[j]] = s;
		}
	}
	dump(used); dump(roop);
	
	rep(i, 0, N) {
		int d = D%roop[i];
		int x = i;
		rep(j, 0, d)x = v[x];
		cout << x+1 << endl;
	}


	return 0;
}