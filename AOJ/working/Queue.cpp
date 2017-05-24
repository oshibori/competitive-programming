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
struct Job {
	char name[20];
	int time;
	Job() {}
	Job(char *c, int t) {
		strcpy(name, c);
		time = t;
	}
};
struct Queue {
	int b, e, len;;
	Job j[100000];
	Queue() {
		len = 100000;
		b = 0;
		e = 0;
	}
	Job front() {
		Job ret = j[b];
		b = (b + 1) % len;
		return ret;
	}
	void push(Job in) {
		j[e] = in;
		e = (e + 1) % len;
	}
	bool empty() {
		return b == e;
	}
};
signed main() {
	int n, q; cin >> n >> q;
	int now = 0;
	static Queue m;
	rep(i, 0, n) {
		char c[20]; int t;
		scanf("%s %d", c, &t);
		m.push(Job(c, t));
	}
	while (!m.empty()) {
		Job tmp = m.front();
		//printf("debug : %s %d\n", tmp.name, tmp.time);
		int x = min(q, tmp.time);
		now += x;
		tmp.time -= x;
		if (tmp.time == 0) {
			printf("%s %d\n", tmp.name, now);
		}
		else {
			m.push(tmp);
		}
	}
	return 0;
}