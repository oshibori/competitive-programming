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
static const int MAX = 1000;
static const int VMAX = 10000;
int n, A[MAX], s;// nは要素数、Aは入力、sは入力の最小値
int B[MAX], T[VMAX + 1];
int solve() {
	int ans(0);
	bool V[MAX];
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
		V[i] = false;
	}
	sort(B, B + n);
	for (int i = 0; i < n; i++)T[B[i]] = i;
	for (int i = 0; i < n; i++) {
		if (V[i])continue;
		int cur = i;
		int S = 0;// sum of values in a cycle
		int m = VMAX;//minimum value in a cycle
		int an = 0;// number of values in a cycle
		while (1) {
			V[cur] = true;
			an++;
			int v = A[cur];
			m = min(m, v);
			S += v;
			cur = T[v];
			if (V[cur])break;
		}
		ans += min(S + (an - 2)*m, m + S + (an + 1)*s);
	}
	return ans;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	s = VMAX;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		s = min(s, A[i]);
	}
	cout << solve() << endl;
	return 0;
}