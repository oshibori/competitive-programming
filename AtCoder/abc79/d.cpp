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
    int H,W;cin>>H>>W;
    vector<vector<int>>c(10,vector<int>(10));
    rep(i,0,10)rep(j,0,10)cin>>c[i][j];
    rep(i,0,10)c[i][i]=0;
    rep(k,0,10)rep(i,0,10)rep(j,0,10)
        chmin(c[i][j],c[i][k]+c[k][j]);
    long long ans(0);
    rep(i,0,H)rep(j,0,W){
        int a;cin>>a;
        if(a!=-1)ans+=c[a][1];
    }
    cout<<ans<<endl;

    return 0;
}
