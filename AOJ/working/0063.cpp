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
int main() {
	string s;
	int cnt = 0;
	while (cin >> s) {
		bool f = true;
		for (int i = 0; i < s.length()/2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				f = false;
				break;
			}
		}

		if (f)cnt++;
	}
	cout << cnt << endl;
	return 0;
}