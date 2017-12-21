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
 
bool g(string a,string b){
    rep(i,0,a.size()){
        if(a[i]==b[i]||a[i]=='?'||b[i]=='?')continue;
        return false;
    }
    return true;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    string S,T;cin>>S>>T;
    bool f(false);
    for(int i=S.size()-T.size();i>=0;i--){
        if(g(T,S.substr(i,T.size()))){

            f=true;
            rep(j,0,T.size())S[i+j]=T[j];
            break;
        }
    }
    if(!f){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }

    rep(i,0,S.size())if(S[i]=='?')S[i]='a';
    cout<<S<<endl;

        
    
	return 0;
}

