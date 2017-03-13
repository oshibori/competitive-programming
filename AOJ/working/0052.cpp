#define _USE_MATH_DEFINES
#include<iostream>
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
#define EPS 1e-10
using namespace std;
typedef long long llong;
llong dp[20001];
int main() {
	int n;
	dp[0] = 0;
	for (int i = 1; i < 20001; i++) {
		dp[i] = dp[i - 1];
		if (i % 5 == 0) {
			int r = i;
			while (r % 5 == 0) {
				dp[i]++;
				r /= 5;
			}
		}
	}
	while (cin >> n&&n) {
		cout << dp[n] << endl;
	}
	return 0;
}