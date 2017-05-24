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
	char suit;
	int value;
	bool operator<(const Card &c) {
		return value < c.value;
	}
	bool operator>(const Card &c) {
		return value > c.value;
	}
	bool operator == (const Card &c) {
		return suit == c.suit&&value == c.value;
	}
};
void bubbleSort(vector<Card>v) {
	vector<Card>w(v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = v.size() - 1; i < j; j--) {
			if (v[j - 1] > v[j])swap(v[j - 1], v[j]);
		}
	}
	rep(i, 0, v.size())cout << v[i].suit << v[i].value << (i == v.size() - 1 ? '\n' : ' ');

	for(int i=0;i<v.size()-1;i++)for(int j=i+1;j<v.size();j++)
		for(int a=0;a<v.size()-1;a++)for(int b=a+1;b<v.size();b++)
			if (w[i] == v[b] && w[j] == v[a]&&w[i].value==w[j].value) {
				cout << "Not stable" << endl;
				dump(i,j,a,b)	
				return;
			}
	cout << "Stable" << endl;
	return;
}
void selectionSort(vector<Card>v) {
	vector<Card>w(v);
	rep(i, 0, v.size()) {
		int index = i;
		rep(j, i + 1, v.size())if (v[index] > v[j])index = j;
		swap(v[i], v[index]);
	}
	rep(i, 0, v.size())cout << v[i].suit << v[i].value << (i == v.size() - 1 ? '\n' : ' ');

	for (int i = 0; i<v.size() - 1; i++)for (int j = i + 1; j<v.size(); j++)
		for (int a = 0; a<v.size() - 1; a++)for (int b = a + 1; b<v.size(); b++)
			if (w[i] == v[b] && w[j] == v[a]&& w[i].value == w[j].value) {
				cout << "Not stable" << endl;
				return;
			}
	cout << "Stable" << endl;
	return;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<Card>v(N);
	rep(i, 0, N) {
		cin >> v[i].suit >> v[i].value;
	}
	bubbleSort(v);
	selectionSort(v);
	return 0;
}