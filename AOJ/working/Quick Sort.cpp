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
struct Card {
	char c;
	int v;
	Card() {}
	Card(int a) :v(a) {}
	bool operator<=(const Card &p) const{
		return v <= p.v;
	}
	bool operator==(const Card &p) const{
		return c == p.c&&v == p.v;
	}
};
istream &operator >> (istream &is, Card &p) {
	is >> p.c >> p.v;
	return is;
}
ostream &operator<<(ostream &os, Card &p) {
	os << p.c << " " << p.v;
	return os;
}
int partition(vector<Card>&a, int l, int r) {
	Card v = a[r];
	int i(l - 1);
	rep(j, l, r) {
		if (a[j]<=v) {
			swap(a[++i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void quicksort(vector<Card>&a, int l, int r) {
	if (l < r) {
		int p = partition(a, l, r);
		quicksort(a, l, p - 1);
		quicksort(a, p + 1, r);
	}
}
template<typename T>
void merge(vector<T>&a, int l, int r) {
	int mid = (l + r) / 2;
	int n1 = mid - l, n2 = r - mid;
	vector<T>L(n1 + 1), R(n2 + 1);
	rep(i, 0, n1)L[i] = a[l + i];
	L[n1] = T(INF);
	rep(i, 0, n2)R[i] = a[mid + i];
	R[n2] = T(INF);
	int i(0), j(0);
	rep(k, l, r) {
		if (L[i] <= R[j])a[k] = L[i++];
		else a[k] = R[j++];
	}
}
template<typename T>
void mergesort(vector<T>&a, int l, int r) {
	if (r - l > 1) {
		int mid = (l + r) / 2;
		mergesort(a, l, mid);
		mergesort(a,mid, r);
		merge(a, l, r);
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<Card>c(N); rep(i, 0, N)cin >> c[i];
	vector<Card>cm(c), cq(c);
	quicksort(cq, 0, N - 1);
	mergesort(cm, 0, N);
	if (cq == cm)cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	rep(i, 0, N)cout << cq[i] << endl;
	return 0;
}