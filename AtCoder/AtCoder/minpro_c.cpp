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
// binary search
void solve1() {
	int N, K; cin >> N >> K;
	vector<int> A(K); rep(i, 0, K) { cin >> A[i]; A[i]--; }
	vector<string> S(N); rep(i, 0, N) { cin >> S[i]; }

	int len(INF);
	rep(i, 0, K)chmin(len, (int)S[A[i]].size());

	string T;
	rep(i, 0, len) {
		bool f(true);

		rep(j, 1, K) {
			if (S[A[j]][i] != S[A[j - 1]][i]) {
				f = false;
				break;
			}
		}

		if (f)T.push_back(S[A[0]][i]);
		else break;

	}

	dump(T);


	vector<int>hit(N, 0);
	rep(i, 0, K)hit[A[i]]++;

	int l = -1, r = T.size() + 1;
	// [l,r)
	while (r - l > 1) {
		int mid = (l + r) / 2;
		bool f(true);
		rep(i, 0, N) {
			if ((S[i].substr(0, mid) == T.substr(0, mid)) ^ (hit[i] == 1))f = false;
		}

		if (f)r = mid;
		else l = mid;

	}

	dump(l, r);
	if (l == T.size())cout << "-1" << endl;
	else cout << T.substr(0, r) << endl;
}

void solve2() {
	int N, K; cin >> N >> K;
	vector<int> A(K); rep(i, 0, K) { cin >> A[i]; A[i]--; }
	vector<int>hit(N, 0);
	rep(i, 0, K)hit[A[i]]++;
	vector<string> S(N); rep(i, 0, N) { cin >> S[i]; }
	string Sr = S[A[0]];

	int m(INF), M(-1);
	rep(i, 0, N) {
		int index(0);
		for (int j = 0; j < min(Sr.size(), S[i].size()) && Sr[j] == S[i][j]; j++)index++;
		
		if(hit[i])chmin(m, index);
		else chmax(M, index);
	}

	if (M < m)cout << Sr.substr(0, M + 1) << endl;
	else cout << "-1" << endl;

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	// solve1();
	solve2();
	return 0;
}