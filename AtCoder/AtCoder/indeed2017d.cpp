#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

const int M = 20;
int n;
Weight best[1 << M][M];
int    prev[1 << M][M];
void buildPath(int S, int i, vector<int> &path) {
	if (!S) return;
	buildPath(S ^ (1 << i), prev[S][i], path);
	path.push_back(i);
}
Weight shortestHamiltonPath(Matrix w, int s, vector<int> &path) {
	int N = 1 << n;
	REP(S, N) REP(i, n) best[S][i] = INF;
	best[1 << s][s] = 0;
	REP(S, N) REP(i, n) if (S&(1 << i)) REP(j, n)
		if (best[S | (1 << j)][j] > best[S][i] + w[i][j])
			best[S | (1 << j)][j] = best[S][i] + w[i][j],
			prev[S | (1 << j)][j] = i;
	int t = min_element(best[N - 1], best[N - 1] + n) - best[N - 1];
	path.clear(); buildPath(N - 1, t, path);
	return best[N - 1][t];
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<vector<int>>m(n, vector<int>(n));
	rep(i, 0, n) {
		rep(j, 0, n) {
			int d; cin >> d;
			m[i][j] = d;
		}
	}
	cout<<shortestHamiltonPath(m,)
	return 0;
}