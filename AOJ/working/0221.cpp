#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
string backst(int cnt) {
	string s;
	while (cnt) {
		s += to_string(cnt % 10);
		cnt /= 10;
	}
	return s;
}
string fizzbuzz(int x) {
	if (x % 15 == 0)return "FizzBuzz";
	else if (x % 5 == 0)return "Buzz";
	else if (x % 3 == 0)return "Fizz";
	else {
		ostringstream os;
		os << x;
		return os.str();
	}
}
signed main() {
	int m, n;
	while (cin >> m >> n, m || n) {
		vector<bool>v(m, true);// v[0] = false;
		int cnt(1), index(0);
		string s;
		while (n--) {
			cin >> s;
			if (v.size() == 1)continue;
			if (accumulate(all(v), 0) == 1)continue;
			while (v[index%m] == false)index++;

			if (fizzbuzz(cnt) != s)v[index%m] = false;

			cnt++; index++;
		}
		bool f(true);
		rep(i, 0, m) {
			if (v[i]) {
				if (f)f = false;
				else cout << " ";
				cout << i + 1 ;
			}
		}
		cout << endl;
	}
	return 0;
}