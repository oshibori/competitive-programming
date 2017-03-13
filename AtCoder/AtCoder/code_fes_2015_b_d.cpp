#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>
#include<utility>
using namespace std;
typedef long long llong;
int main() {
	int n; cin >> n;
	vector<pair<llong, llong>>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		for (int j = 0; j < i; j++) {
			if(v[])
		}
	}
}
//static bool f[1000000];
//int main() {
//	for (int i = 0; i < 1000000; i++)f[i] = false;
//	int n; cin >> n;
//	vector<int>s(n), c(n);
//	for (int i = 0; i < n; i++) {
//		llong cnt = 0;
//		cin >> s[i] >> c[i];
//		if (s[i] + c[i] > 100000) {
//
//		}
//		int x = s[i];
//		while (1) {
//			if (f[x] == false) {
//				f[x] = true;
//				cnt++;
//				if (cnt == c[i])break;
//			}
//			x++;
//		}
//		cout << x << endl;
//	}
//	return 0;
//}