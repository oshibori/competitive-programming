#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#include<complex>
#define EPS 1e-10
using namespace std;
typedef long long llong;
int main() {
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		vector<int>base(4,0);
		int out = 0, score = 0;
		while (out!=3) {
			cin >> s;
			if (s == "OUT")out++;
			else if (s == "HIT") {
				for (int j = 3; 0 < j; j--) {
					base[j] = base[j - 1];
				}
				base[0] = 1;
				if (base[3] == 1) {
					base[3] = 0;
					score++;
				}
			}
			else if (s == "HOMERUN") {
				int cnt = 0;
				for (int j = 0; j < 3; j++) {
					if (base[j] == 1) {
						cnt++;
						base[j] = 0;
					}
				}
				score += 1 + cnt;
			}
		}
		cout << score << endl;
	}
	return 0;
}