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

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, W; cin >> N >> W;
	vector<int>v, w;
	rep(i, 0, N) {
		int a, b, c; cin >> a >> b >> c;
		int j(0);
		// ��c��2�i��(bit)�ŕ�������
		// ������̐����̘a�݂̂�1����c�܂ł̑S�Ă̐�����2�i���ŕ\���ł���悤�ɂ���
		// c����2^x++(0<=x)�����ԂɈ����Ă����ƁA����ȏ�����Ȃ��Ȃ�2^x�ɓ��B����
		// ���̂Ƃ�������̐����̘a�́@a=0...00111...1111��
		// b=0...00BBB...BBBB(B�͂ǂꂩ�����1�Ŏc��͑S��0�ł���)
		// �̘a�ł���(= c)
		// a��1�ɂȂ��Ă���bit��on-off�����R�ɐ؂�ւ��邱�Ƃɂ����
		// [0,a]�̐��������R�ɕ\���ł���B
		// a+b��c��\���ł��邪([c])�A���̂Ƃ�c��2�i���\����
		// c=0...01000...011...1111�Ȃ��Ă���B
		// ���̂Ƃ�b�ȉ���2^x�͕K��������݂��Ă���B
		// ����Ă�����bit�����R��on-off�ɐ؂�ւ��邱�Ƃɂ����
		// [a+1,c)�̐��������R�ɕ\���ł���
		// ����������[0,a],[a+1,c),[c]���\���ł���̂ŁA
		// ����c��2^x++(0<=x)�ōŏ��̗v�f���ɕ������邱�Ƃ��ł���ƌ�����B

		while (c) {
			int x = min(c, (1 << j++));
			c -= x;
			v.emplace_back(x*a);
			w.emplace_back(x*b);
		}
	}
	vector<int>dp(W + 1, 0);
	rep(i, 0, v.size())rrep(j, w[i], W + 1)
		chmax(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W] << endl;
	return 0;
}