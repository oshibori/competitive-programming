#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;
typedef long long llong;
int main() {
	int x,n, m;
	cin >> n >> m;
	vector<int>v(m+1,0);
	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x]++;
		if (v[x] > n / 2) {
			cout << x << endl;
			return 0;
		}
	}
	cout << '?' << endl;
	return 0;
}