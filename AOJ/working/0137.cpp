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
		int x;
		cin >> x;
		cout << "Case " << i+1 << ":" << endl;
		for (int j = 0; j < 10; j++) {
			string s;
			x *= x;
			string t = to_string(x);
			for (int k = 0; k < 8 - t.length(); k++) {
				s += '0';
			}
			s += t;
			x = stoi(s.substr(2, 4));
			cout << x << endl;

		}
	}
	return 0;
}