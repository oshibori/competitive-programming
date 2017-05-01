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
struct RangeMinimumQuery {
	// 0-indexed�Ŗ؂��\��
	int n;
	vector<int>d;
	RangeMinimumQuery(int m) {
		// m is the number of data
		// �ȒP�ɂ��邽�߁A�v�f�����Q�ׂ̂����
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	void update(int i, int x) {
		// update ith (0-indexed) number
		// index i �ɑΉ�����leaf node ��
		// The index of leaf node which corresponds to ith num is (n+i-1).
		i += n - 1;
		d[i] = x;
		while (i > 0) {
			i = (i - 1) / 2;// parent:(n-1)/2
			d[i] = min(d[i * 2 + 1], d[i * 2 + 2]);// children: (2*n+1),(2*n+2)
			// �ȒP�ɐe��q�ɃA�N�Z�X�ł���
			// ���̔ԍ��t������肭�����̂́A
			// This is because SegmentTree is a complete binary tree.
		}
	}
	int query(int l, int r) {
		// query [l,r)
		return query(l, r, 0, 0, n);// n�łȂ��Ɗ��S�񕪖؂ɂȂ�Ȃ�
	}
	int query(int a, int b, int k, int l, int r) {
		// query for min of [a,b)
		// ���̕��̈����́A�v�Z�̊ȒP���̂��߂̈���
		// k�͐ߓ_�̔ԍ��Al,r �͂��̐ߓ_��[l,r)�ɑΉ��t���Ă��邱�Ƃ�\��
		// ���������āA�O�����query(a,b,0,0,n)�Ƃ��ČĂ�

		// [a,b) �� [l,r)���������Ȃ����INF
		if (r <= a || b <= l)return INF;

		// [a,b)��[l,r)�����S�Ɋ܂�ł���΁A���̐ߓ_�̒l
		if (a <= l&&r <= b)return d[k];
		else {
			//�����łȂ���΁A2�̎q�̍ŏ��l
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RangeMinimumQuery rmq(n);
	rep(i, 0, q) {
		int com; cin >> com;
		int x, y; cin >> x >> y;
		if (com)cout << rmq.query(x, y + 1) << endl;
		else rmq.update(x, y);
	}
	dump(rmq.d);
	return 0;
}