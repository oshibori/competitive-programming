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
	cin >> s;
	bool f = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'C') {
			for (int j = i+1; j < s.length(); j++) {
				if (s[j] == 'F') {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}