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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
class Box {
public:
	int w, h;
	Box(int w, int h) :w(w), h(h) {}
	//bool operator< (const Box &other) {
	//	return w != other.w ? w < other.w : h < other.h;
	//}
	bool operator< (const Box &other) {
		return w < other.w&&h < other.h;
	}

};

ostream &operator<<(ostream &os, const Box &b) {
	os << "w:" << b.w << " h:" << b.h;
	return os;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<Box>v;
	rep(i, 0, N) {
		int w, h; cin >> w >> h;
		v.emplace_back(Box(w, h));
	}
	sort(all(v), [](const Box &a, const Box &b) {return a.w != b.w ? a.w < b.w : a.h > b.h; });
	dump(v);
	vector<Box>L; L.emplace_back(v[0]);

	rep(i, 1, N) {
		if (L.back() < v[i])L.emplace_back(v[i]);
		else *lower_bound(all(L), v[i]) = v[i];
	}

	dump(L);

	cout << L.size() << endl;

	return 0;
}