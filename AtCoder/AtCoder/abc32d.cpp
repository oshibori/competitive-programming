#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const double EPS = 1e-10;
class P {
public:
	int v, w;
	bool operator<(const P &other) {
		return (w != other.w) ? w < other.w : v < other.v;
	}
	P(int x, int y) {
		v = x;
		w = y;
	}
};
void half(P x, int deep, vector<P> &set, vector<P> &list) {
	if (deep == list.size()) {
		set.push_back(x);
		return;
	}
	half(x, deep + 1, set, list);
	x.v += list[deep].v;
	x.w += list[deep].w;
	half(x, deep + 1, set, list);
	return;
}

void print_set(const vector<P>&v) {
	if (DBG) {
		cout << endl;
		rep(i, 0, v.size()) {

			cout << v[i].v << " " << v[i].w << endl;
		}
	}
}

signed main() {
	int N, W;
	cin >> N >> W;
	if (N <= 30) {
		vector<P>listA, listB, setA, setB;
		int na = N / 2, nb = N - na;
		rep(i, 0, na) {
			int w, v; cin >> v >> w;
			listA.push_back(P(v, w));
		}
		rep(i, 0, nb) {
			int w, v; cin >> v >> w;
			listB.push_back(P(v, w));
		}
		P x(0, 0);
		half(x, 0, setA, listA);
		half(x, 0, setB, listB);

		sort(all(setA));

		vector<P>setA_n;
		rrep(i, 0, setA.size()) {
			bool f = true;
			rrep(j, 0, i) {
				if (setA[i].w > setA[j].w&&setA[i].v < setA[j].v)f = false;
			}
			if (f)setA_n.push_back(setA[i]);
		}
		sort(all(setA_n));

		int ans(0);

		rep(i, 0, setB.size()) {
			int l = 0, r = setA_n.size();
			while (r - l > 1) {
				int mid = (l + r) / 2;
				if (setA_n[mid].w + setB[i].w <= W)l = mid;
				else r = mid;
			}
			if (setB[i].w + setA_n[l].w <= W)ans = max(ans, setB[i].v + setA_n[l].v);
		}

		cout << ans << endl;
	}

	else {
		int v_m(-1), w_m(-1);
		vector<int>v(N + 1), w(N + 1);
		rep(i, 1, N + 1) {
			cin >> v[i] >> w[i];
			v_m = max(v_m, v[i]);
			w_m = max(w_m, w[i]);
		}
		if (w_m <= 1000) {
			W = min(W, N*w_m);
			vector<int>dp(W + 1, 0);
			rep(i, 1, N + 1) {
				rrep(j, w[i], W + 1) {
					dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
				}
			}
			cout << dp[W] << endl;
		}
		else if (v_m <= 1000) {
			int V = N*v_m;
			vector<int>dp(V + 1, INF); dp[0] = 0;
			rep(i, 1, N + 1) {
				rrep(j, v[i], V + 1) {
					dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
				}
			}
			int ans(0);
			rep(i, 0, V + 1)if (dp[i] <= W)ans = i;
			cout << ans << endl;
		}
	}
	return 0;
}