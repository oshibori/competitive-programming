#include "bits/stdc++.h"
using namespace std;
 
//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<(o)<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
 
class Space {
public:
    int X, Y, Z;
    const int dx[13] = { 0,1,1,1,0,0,-1,-1,-1,1,1,1,0 };
    const int dy[13] = { 1,1,1,1,1,1,1,1,1,0,0,0,0 };
    const int dz[13] = { 0,-1,0,1,-1,1,-1,0,1,-1,0,1,1 };
    vector<vector<vector<int>>> P;
    vector<vector<int>> S;
    Space(int X, int Y, int Z) :X(X), Y(Y), Z(Z) {
        P = vector<vector<vector<int>>>(X, vector<vector<int>>(Y, vector<int>(Z, -1)));
        S = vector<vector<int>>(X, vector<int>(Y, 0));
    }
    bool inrange(int x, int y, int z) {
        return 0 <= x&&x < X && 0 <= y && y < Y && 0 <= z && z < Z;
    }
    int count(int x, int y, int z, int d, int t, int r) {
        if (P[x][y][z] != t)return 0;
        int nx = x + dx[d] * r, ny = y + dy[d] * r, nz = z + dz[d] * r;
        return inrange(nx, ny, nz) ? count(nx, ny, nz, d, t, r) + 1 : 1;
    }
    void update(int x, int y, int value) {
        P[x][y][S[x][y]++] = value;
    }
    int query(int x, int y, int turn, int M) {
        update(x, y, turn);
        int ret = 0;
        for (int d = 0; d < 13; d++) {
            int cnt = 0;
            cnt += count(x, y, S[x][y] - 1, d, turn, 1);
            cnt += count(x, y, S[x][y] - 1, d, turn, -1);
            cnt--;
            if (cnt >= M)
                return turn;
        }
        return -1;
    }
};
 
 
 
signed main() {
    for (int N, M, P; cin >> N >> M >> P&&N;) {
        Space S(N, N, N);
        vector<int> x(P), y(P);
        rep(i, 0, P) {
            cin >> x[i] >> y[i];
            x[i]--, y[i]--;
        }
        bool draw = true;
        rep(i, 0, P) {
            int res = S.query(x[i], y[i], i & 1, M);
            if (res == 1) {
                cout << "White " << i + 1 << endl;
                draw = false;;
                break;
            }
            else if (res == 0) {
                cout << "Black " << i + 1 << endl;
                draw = false;
                break;
            }
        }
        if (draw)cout << "Draw" << endl;
    }
}
