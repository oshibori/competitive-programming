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

signed main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case '0':
			if (s[i + 1] == 'U') {
				cout << "nn";
				i++;
			}
			else cout << 'w';
			break;
		
			
		case '2':cout << 'k' ; break;
		case '3':cout << 's' ; break;
		case '4':cout << 't' ; break;
		case '5':cout << 'n' ; break;
		case '6':cout << 'h' ; break;
		case '7':cout << 'm' ; break;
		case '8':cout << 'y' ; break;
		case '9':cout << 'r' ; break;
		case 'T':cout << 'a' ; break;
		case 'L':cout << 'i' ; break;
		case 'U':cout << 'u' ; break;
		case 'R':cout << 'e' ; break;
		case 'D':cout << 'o' ; break;
		default:break;
		}


	}
	cout << endl;
	return 0;
}