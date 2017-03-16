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
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int Deg, Dis; cin >> Deg >> Dis;
	string Dir; int w;
	double s = Dis / 60.0;
	dump(s);
	s *= 10;
	dump(s);
	s = round(s);
	s /= 10;
	dump(s);

	if (s <= 0.2)w = 0;
	else if (s <= 1.5)w = 1;
	else if (s <= 3.3)w = 2;
	else if (s <= 5.4)w = 3;
	else if (s <= 7.9)w = 4;
	else if (s <= 10.7)w = 5;
	else if (s <= 13.8)w = 6;
	else if (s <= 17.1)w = 7;
	else if (s <= 20.7)w = 8;
	else if (s <= 24.4)w = 9;
	else if (s <= 28.4)w = 10;
	else if (s <= 32.6)w = 11;
	else w = 12;



















	if (3487.5 <= Deg)Dir = "N";
	else if (3262.5 <= Deg)Dir = "NNW";
	else if (3037.5 <= Deg)Dir = "NW";
	else if (2812.5 <= Deg)Dir = "WNW";
	else if (2587.5 <= Deg)Dir = "W";
	else if (2362.5 <= Deg)Dir = "WSW";
	else if (2137.5 <= Deg)Dir = "SW";
	else if (1912.5 <= Deg)Dir = "SSW";
	else if (1687.5 <= Deg)Dir = "S";
	else if (1462.5 <= Deg)Dir = "SSE";
	else if (1237.5 <= Deg)Dir = "SE";
	else if (1012.5 <= Deg)Dir = "ESE";
	else if (787.5 <= Deg)Dir = "E";
	else if (562.5 <= Deg)Dir = "ENE";
	else if (337.5 <= Deg)Dir = "NE";
	else if (112.5 <= Deg)Dir = "NNE";
	else Dir = "N";


	if (w == 0)Dir = "C";

	cout << Dir << " " << w << endl;




	return 0;
}