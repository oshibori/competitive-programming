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
void print_v(vector<int>v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		vector<int>v(8), w(8);
		for (int i = 0; i < s.length(); i++) {
			v[i] = s[i] - '0';
			w[i] = v[i];
		}
		//print_v(v);
		sort(v.begin(), v.end());
		//print_v(v);
		sort(w.begin(), w.end(), greater<int>());
		//print_v(w);
		for (int i = s.length() - 1; i >= 0; i--) {
			w[i] -= v[i];
			if (w[i] < 0) {
				w[i - 1]--;
				w[i] += 10;
			}
		}
		cout << w[7] +w[6] * 10 + w[5] * 100 + w[4] * 1000 + w[3] * 10000 + w[2] * 100000 + w[1] * 1000000 + w[0] * 10000000 << endl;
	}
	return 0;
}