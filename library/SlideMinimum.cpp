#include<vector>
#include<deque>
#include<functional>
using namespace std;

vector<int> slide_minimum(vector<int>x,int k){
    vector<int>y(x.size()-k+1);
    deque<int>deq;
    for(int i=0;i<x.size();i++){
        while(deq.size() and x[deq.back()]>=x[i])deq.pop_back();
        deq.push_back(i);
        if(i-(k-1)>=0){
            y[i-(k-1)]=x[deq.front()];
            if(deq.front()==i-(k-1))deq.pop_front();
        }
    }
    return y;
}

template<typename T>
vector<T> slide_minimum(vector<T>x,int k,function<bool(T,T)>comp){
    vector<T>y(x.size()-k+1);
    deque<T>deq;
    for(int i=0;i<x.size();i++){
        while(deq.size() and !comp(x[deq.back()],x[i]))deq.pop_back();
        deq.push_back(i);
        if(i-k+1>=0){
            y[i-k+1]=x[deq.front()];
            if(deq.front()==i-k+1)deq.pop_front();
        }
    }
    return y;
}