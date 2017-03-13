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
	while (cin >> s) {
		vector<vector<int>>v(10, vector<int>(10));
		for (int i = 0; i < 10; i++) {
			v[0][i] = s[i] - '0';
		}
		int n = 9;
		//for (int k = 0; k < n+1; k++) {
		//	cout << v[0][k] << " ";
		//}
		//cout << endl;
		for (int i = 1; i < 10; i++) {
			int j = 0;
			while (j < n) {
				v[i][j] = (v[i - 1][j] + v[i - 1][j + 1]) % 10;
				j++;
			}
			//for (int k = 0; k < n; k++) {
			//	cout << v[i][k] << " ";
			//}
			//cout << endl;
			n--;
		}
		cout << v[9][0] << endl;
	}
	return 0;
}