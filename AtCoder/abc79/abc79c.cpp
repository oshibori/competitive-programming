#include <bits/stdc++.h>
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

    string s;cin>>s;
    s.insert(1," ");
    s.insert(3," ");
    s.insert(5," ");
    auto eval=[&](string a){
        int v=a[0]-'0';
        v+=(a[1]=='+'?1:-1)*(a[2]-'0');
        v+=(a[3]=='+'?1:-1)*(a[4]-'0');
        v+=(a[5]=='+'?1:-1)*(a[6]-'0');
        return v==7;
    };

    rep(i,0,2)rep(j,0,2)rep(k,0,2){
        if(i)s[1]='+';
        else s[1]='-';

        if(j)s[3]='+';
        else s[3]='-';

        if(k)s[5]='+';
        else s[5]='-';

        if(eval(s)){
            cout<<s+"=7"<<endl;
            return 0;
        }
    }
    return 0;
}
