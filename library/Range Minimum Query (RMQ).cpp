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
const int INF = (1ll << 31) - 1;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
struct RangeMinimumQuery {
	// 1-indexed�Ŗ؂��\��
	// ���ꂼ��̗v�f�� 0-indexed
	int n;
	vector<T>d;
	RangeMinimumQuery(int m) {
		// m is the number of data
		// �ȒP�ɂ��邽�߁A�v�f�����Q�ׂ̂����
		for (n = 1; n < m; n <<= 1);
		d.assign(2 * n, INF);
	}
	void update(int i, T x) {
		// update ith (0-indexed) number
		// index i �ɑΉ�����leaf node ��
		// The index of leaf node which corresponds to ith num is (n+i).
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			d[j] = min(d[j * 2], d[j * 2 + 1]);// children: (2*n),(2*n+1)
			// �ȒP�ɐe��q�ɃA�N�Z�X�ł���
			// This is because SegmentTree is a complete binary tree.
		}
	}
	T query(int l, int r) {
		// query [l,r)
		return query(l, r, 1, 0, n);// n�łȂ��Ɗ��S�񕪖؂ɂȂ�Ȃ�
	}
	T query(int a, int b, int k, int l, int r) {
		// query for min of [a,b)
		// ���̕��̈����́A�v�Z�̊ȒP���̂��߂̈���
		// k�͐ߓ_�̔ԍ��Al,r �͂��̐ߓ_��[l,r)�ɑΉ��t���Ă��邱�Ƃ�\��
		// ���������āA�O�����query(a,b,1,0,n)�Ƃ��ČĂ�

		// [a,b) �� [l,r)���������Ȃ����INF
		if (r <= a || b <= l)return INF;

		// [a,b)��[l,r)�����S�Ɋ܂�ł���΁A���̐ߓ_�̒l
		if (a <= l&&r <= b)return d[k];
		else {
			//�����łȂ���΁A2�̎q�̍ŏ��l
			T vl = query(a, b, k * 2, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 1, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, q; cin >> n >> q;
	RangeMinimumQuery<int> rmq(n);
	rep(i, 0, q) {
		int com; cin >> com;
		int x, y; cin >> x >> y;
		if (com)cout << rmq.query(x, y + 1) << endl;
		else rmq.update(x, y);
	}
	//dump(rmq.d);
	return 0;
}