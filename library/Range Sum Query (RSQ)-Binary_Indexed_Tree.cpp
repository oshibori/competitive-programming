﻿#include "bits/stdc++.h"
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
template<typename T>
struct BinaryIndexedTree {
	// 1-indexed
	int n;
	vector<T>d;
	// d[x] が管理する区間の長さは，x の最も下の立っているビット(x&-x)
	BinaryIndexedTree(int m) : n(m) {
		// 0 以外の値で初期化をするとき
		// ・add を 𝑁 回呼び出せば 𝑂(𝑁 log 𝑁)
		// ・𝑣𝑥 = 1 で初期化するなら bit[x] = x & -x; (x&-x は区間の長さ)
		// ・一般には bit[x] を 𝑣𝑥 で初期化したのち
		//   for (int x = 1; x < N; ++x) bit[x + (x & -x)] += bit[x];
		d.assign(m + 1, 0);
	}
  // [a,b] 1-indexed
	T sum(int a, int b) {
		return sum(b) - sum(a - 1);
	}
	T sum(int i) {
		// iから0にiの最も下の立っているbitを使って到達する最短距離
		// 次に足すべき区間は，番号から区間の長さを引くと求まる
		T ret(0);
		for (int j = i; j > 0; j -= j&(-j))ret += d[j];
		return ret;
	}
	void add(int i, T x) {
		// iからnにiの最も下の立っているbitを使って到達する最短距離
		// 次に更新すべき区間は，番号に区間の長さを足すと求まる
		for (int j = i; j <= n; j += j&(-j))d[j] += x;
	}
	int lower_bound(T w) {
		// 二分木の分かれ方に従って二分探索する
		// 左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい (index/2)
		// ちょうど BIT がもっている情報，𝑂(1) 時間で得られる
		//
		if (w <= 0)return 0;
		int x(0),y;
		for (y = 1; 2 * y <= n; y <<= 1);
		for (int k = y; k > 0; k >>= 1) {
			if (x + k <= n&&d[x + k] < w) {
				w -= d[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	BinaryIndexedTree<int> BIT(n);
	rep(i, 0, q) {
		int com, a, b; cin >> com >> a >> b;
		if (com)cout << BIT.sum(a, b) << endl;
		else BIT.add(a, b);
	}
	//rep(i, 0, n + 1)cout << BIT.d[i] << " ";
	return 0;
}
