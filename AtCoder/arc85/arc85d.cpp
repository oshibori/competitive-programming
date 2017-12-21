#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
const double PI = acos(-1);
const double EPS = 1e-9;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int N,Z,W;
vector<int>X,Y,a;
int x(int,int);
int y(int,int);

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N>>Z>>W;
    vector<int>b(N);
    rep(i,0,N)cin>>b[i];
    a=b;
    X=Y=vector<int>(N+1,-1);
    x(0,-1);
    cout<<X[0]<<endl;
    rep(i,0,N)cerr<<"X["<<i<<"] = "<<X[i]<<", Y["<<i<<"] = "<<Y[i]<<endl;


	return 0;
}


int x(int ind,int prev){
    cerr<<"func x "<<ind<<" "<<prev<<endl;
    if(X[ind]!=-1)return X[ind];
    if(ind==N){
        return X[ind]=prev>=0?a[prev]:Z;
    }

    int ret(-INF);
    rep(k,ind,N){
        chmax(ret,abs(a[k]-y(k+1,ind-1)));
        cerr<<a[k]<<" "<<y(k+1,ind-1)<<endl;
        cerr<<"ret = "<<ret<<endl;
    }
    cerr<<"X["<<ind<<"] = "<<ret<<endl;
    return X[ind]=ret;
}


int y(int ind,int prev){
    cerr<<"func y "<<ind<<" "<<prev<<endl;
    if(Y[ind]!=-1)return Y[ind];
    if(ind==N){
        return Y[ind]=prev>=0?a[prev]:W;
    }

    int ret(INF);
    rep(k,ind,N){
        chmin(ret,abs(a[k]-x(k+1,ind-1)));
        cerr<<a[k]<<" "<<y(k+1,ind-1)<<endl;
        cerr<<"ret = "<<ret<<endl;
    }

    cerr<<"Y["<<ind<<"] = "<<ret<<endl;
    return Y[ind]=ret;
}

