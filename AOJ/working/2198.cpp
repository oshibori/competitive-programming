#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;
class Plant {
public:
	string name;
	int p, a, b, c, d, e, f, s, m;
	int time, income,num;
	double effective;
	Plant(string name, int p, int a, int b, int c, int d, int e, int f, int s, int m) {
		this->name = name;
		this->p = p;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->e = e;
		this->f = f;
		this->s = s;
		this->m = m;

		this->time = a + b + c + d + e + (d + e)*(m - 1);
		this->num = f*m;
		this->income = num*s - p;
		this->effective = this->income / (double)time;
	}
	bool operator<(const Plant &other) {
		return (effective != other.effective ? effective > other.effective : name < other.name);
	}
};
signed main() {
	int n;
	while (cin >> n, n) {
		vector<Plant>v;
		rep(i, 0, n) {
			string l;
			int p, a, b, c, d, e, f, s, m;
			cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			v.push_back(Plant(l, p, a, b, c, d, e, f, s, m));
		}
		sort(all(v));
		rep(i, 0, n) {
			cout << v[i].name << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}