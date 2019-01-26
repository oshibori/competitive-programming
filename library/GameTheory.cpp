#include<vector>
#include<set>
using namespace std;
// 0:=lose,1:=win
bool nim(vector<int>a){
    int x=0;
    for(int i=0;i<a.size();i++){
        x^=a[i];
    }
    return x!=0;
}

// 0:=lose
// メモ化を忘れない
int grundy(int x){
    set<int>s;
    for(;;){
        //s.inesrt(grundy(next_state));
    }
    int g=0;
    while(s.count(g))g++;
    return g;
}