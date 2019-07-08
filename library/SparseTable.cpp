#include "bits/stdc++.h"
using namespace std;

template<typename T>
    struct SparseTable{
        vector<vector<T>> dat;
        vector<int> lookup;
        typedef function<T(T a, T b)> Func;
        Func f;
        T e;

        SparseTable(){}
        SparseTable(const vector<T> &v, Func f, T e){ initialize(v, f, e); }
        void initialize(const vector<T> &v, Func fin, T ein){
            f = fin;
            e = ein;
            int b = 0;
            while((1<<b) <= v.size()) b++;
            int N = 1<<b;
            dat.assign(b, vector<T>(N, e));
            for(int i=0; i<v.size(); i++) dat[0][i] = v[i];

            for(int i=1; i<b; i++){
                int d = 1<<i;
                for(int j=0; j+d<=N; j++){
                    dat[i][j] = f(dat[i-1][j], dat[i-1][j+d/2]);
                }
            }
            lookup.resize(N+1, 0);
            for(int i=2; i<=N; i++){
                lookup[i] = lookup[i>>1] + 1;
            }
        }
        // [l,r]
        T between(int l, int r) {
            r++;
            int b = lookup[r-l];
            return f(dat[b][l], dat[b][r-(1<<b)]);
        }
    };