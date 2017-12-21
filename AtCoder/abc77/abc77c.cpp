#include<bits/stdc++.h>

#define int long long

using namespace std;

signed main(void){
    int N;cin>>N;
    vector<int>A(N),B(N),C(N);
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N;i++)cin>>B[i];
    for(int i=0;i<N;i++)cin>>C[i];
    cerr<<endl;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    for(int i=0;i<N;i++)cerr<<A[i]<<(i==N-1?'\n':' ');
    for(int i=0;i<N;i++)cerr<<B[i]<<(i==N-1?'\n':' ');
    for(int i=0;i<N;i++)cerr<<C[i]<<(i==N-1?'\n':' ');
    cerr<<endl;

//    A.erase(unique(A.begin(),A.end()),A.end());
//    B.erase(unique(B.begin(),B.end()),B.end());
//    C.erase(unique(C.begin(),C.end()),C.end());

   vector<int>v1(B.size()),v2(A.size());
   for(int i=0;i<v1.size();i++){
       v1[i]=N-distance(C.begin(),upper_bound(C.begin(),C.end(),B[i]));
   }
   for(int i=0;i<N;i++)cerr<<v1[i]<<(i==N-1?'\n':' ');
   

   int ans(0);

   for(int i=v1.size()-1;i>0;i--)v1[i-1]+=v1[i];
   for(int i=0;i<N;i++)cerr<<v1[i]<<(i==N-1?'\n':' ');
   cerr<<endl;

   for(int i=0;i<A.size();i++){
      int x = distance(B.begin(),upper_bound(B.begin(),B.end(),A[i]));
      cerr<<x<<" "<<v1[x]<<endl;
      ans += v1[x];
  }

  cout<<ans<<endl;
      
          
}
