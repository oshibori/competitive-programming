#include <bits/stdc++.h>
using namespace std;
 
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
    int N;cin>>N;
    vector<int>t(N),v(N);
    rep(i,0,N)cin>>t[i];
    rep(i,0,N)cin>>v[i];
    vector<int>f(200*101);
    f[0]=0;
    int c(0);
    int t_sum=accumulate(all(t),0);
    rep(i,0,N){
        rep(j,0,t[i]){
            f[c+1]=min(f[c]+1,v[i]);
            c++;
        }
    }
    rep(i,0,t_sum)cerr<<f[i]<<(i==t_sum-1?'\n':' ');
    f[c]=0;
    rrep(i,0,N){

        rrep(j,0,t[i]){
            chmin(f[c-1],min(f[c]+1,v[i]));
            c--;
        }
    }

    rep(i,0,t_sum)cerr<<f[i]<<(i==t_sum-1?'\n':' ');

    double ans(0);

    bool up(true);
    int prev(0);
    int first(0);
    while(f[first]<f[first+1])first++;
    ans+=f[first]*abs(first)/2.0;
    cerr<<"ans = "<<ans<<endl;
    prev=first;
    
    int last=t_sum;
    while(f[last-1]>f[last])last--;
    ans+=f[last]*abs(t_sum-last)/2.0;
    cerr<<"ans = "<<ans<<endl;

    
    cerr<<"!1111111111111111111111111"<<endl;
    rep(i,first+1,last+1){
        if(f[i]==f[i-1]){
            cerr<<"i = "<<i<<endl;
            cerr<<"ans = "<<ans<<endl;
            ans+=abs(prev-i)*f[i];
            prev=i;
        }
        else if(f[i]==f[i+1]){
            cerr<<"i = "<<i<<endl;
            cerr<<"ans = "<<ans<<endl;
            cerr<<"prev = "<<prev<<endl;
            ans+=min(f[prev],f[i])*abs(prev-i);
            ans+=abs(f[prev]-f[i])*abs(prev-i)/2.0;
            prev=i;
        }
        
    }
    cerr<<"!2"<<endl;

    cout<<ans<<endl;
    
	return 0;
}

