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
int cnt(0);
void insertionSort(vector<int>&A, int g) {
	rep(i, g, A.size()) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && v < A[j]) {
			A[j + g] = A[j];
			cnt++;
			j -= g;
		}
		A[j + g] = v;
	}
}
vector<int>g;
void shellSort(vector<int>&A) {
	for (int x = A.size(); x > 0; x >>= 1)g.emplace_back(x);
	rep(i, 0, g.size()) {
		insertionSort(A, g[i]);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>A(n);
	rep(i, 0, n)cin >> A[i];
	shellSort(A);
	cout << g.size() << endl;
	rep(i, 0, g.size())cout << g[i] << (i == g.size()-1 ? '\n' : ' ');
	cout << cnt << endl;
	rep(i, 0, n)cout << A[i] << endl;
	return 0;
}