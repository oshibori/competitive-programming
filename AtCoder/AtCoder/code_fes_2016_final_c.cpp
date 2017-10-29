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

class DisjointSet {
public:
	// �Q�̃O���[�v���P�ɂ܂Ƃ߂�@�Ɓ@2�̗v�f�������O���[�v�ɏ������Ă��邩�ǂ����𔻒肷��
	// �؂��[���Ȃ�΂Ȃ�قǌ����������Ȃ�̂ŁA
	// rank���g�����Ƃɂ��K�v�ȏ�ɐ[�����傫���Ȃ邱�Ƃ��Ȃ��悤�ɊǗ�����
	vector<int>rank, p, S; // p->parent  S[findSet(v)] ->�A�������̑傫��
	DisjointSet() {}
	DisjointSet(int size) {

		S.resize(size, 1);
		rank.resize(size, 0);
		p.resize(size, 0);
		rep(i, 0, size)makeSet(i);
	}
	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	bool same(int x, int y) {   // ���肷��
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y) { // �A������Ƃ��ɂ͂�����g��
		if (same(x, y))return;
		link(findSet(x), findSet(y));
	}
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}

		S[x] = S[y] = S[x] + S[y];
	}
	int findSet(int x) {
		if (x != p[x]) {
			p[x] = findSet(p[x]);// path compression
		}
		return p[x];
	}
	int connectedComponentSize(int x) {
		return S[findSet(x)];
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<vector<int>>v(N);
	set<int>spoken;
	DisjointSet union_find(M);

	rep(i, 0, N) {
		int K; cin >> K;
		rep(j, 0, K) {
			int l; cin >> l;
			l--;
			v[i].emplace_back(l);
			spoken.insert(l);

			union_find.unite(v[i][0], l);

		}
	}

	cout << (spoken.size() == union_find.connectedComponentSize(v[0][0]) ? "YES" : "NO") << endl;


	return 0;
}