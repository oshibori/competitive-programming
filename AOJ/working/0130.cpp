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
	for (int i = 0; i < n; i++) {
		string s,ans;
		cin >> s;
		ans = s[0];
		for (int j = 1; j < s.length(); j++) {
			if (isalpha(s[j])) {
				if (find(ans.begin(), ans.end(), s[j]) != ans.end())continue;

				if (s[j - 2] == '-'&&s[j - 1] == '>') {
					ans += s[j];
				}
				else if (s[j - 2] == '<'&&s[j - 1] == '-') {
					ans = s[j] + ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}