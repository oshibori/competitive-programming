#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int unsigned long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int mod = (int)(1e9 + 7);
const double EPS = 1e-10;
using ll = long long;
class Mod {
public:
	int num;
	Mod() : Mod(0) {}
	Mod(long long int n) : num((n % mod + mod) % mod) {}
	Mod(int n) : Mod(static_cast<long long int>(n)) {}
	operator int() { return num; }
};
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator^(const Mod a, const int n) { if (n == 0) return Mod(1); Mod res = (a * a) ^ (n / 2); if (n % 2) res = res * a; return res; }
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) { assert(b.num != 0); return a * inv(b); }



signed main() {
	int A, B, C; cin >> A >> B >> C;
	Mod a(A), b(B), c(C);


	Mod cf, r;
	Mod X(a*b + a*c - b*c);

	cf = (b*c - a*b)/X;
	r = (b*c - a*c)/X;

	cout << r << " " << cf << endl;
	return 0;
}