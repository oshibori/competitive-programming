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
int merge(vector<int>&a, int l, int mid, int r) {
	int n1 = mid - l;
	int n2 = r - mid;
	vector<int>L(n1 + 1), R(n2 + 1);
	rep(i, 0, n1)L[i] = a[l + i];
	L[n1] = INF;
	rep(i, 0, n2)R[i] = a[mid + i];
	R[n2] = INF;
	int ret(0), i(0), j(0);
	rep(k, l, r) {
		if (L[i] <= R[j]) {
			ret += n2 - j;
			a[k] = L[i++];
		}
		else {
			a[k] = R[j++];
		}
	}
	return ret;
}
int mergeSort(vector<int>&a, int l, int r) {
	if (r - l > 1) {
		int mid = (l + r) / 2;
		return mergeSort(a, l, mid) + mergeSort(a, mid, r) + merge(a, l, mid, r);
	}
	else return 0;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K; cin >> N >> K;
	vector<int> a(N + 1); rep(i, 1, N + 1) { cin >> a[i]; }
	a[0] = 0;
	rep(i, 1, N + 1)a[i] += a[i - 1];
	rep(i, 1, N + 1) {
		a[i] -= i*K;
	}
	cout << mergeSort(a, 0, N + 1) << endl;
	return 0;
}