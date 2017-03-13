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
using namespace std;
typedef long long llong;
int main() {
	int n, m;
	cin >> n >> m;
	if (n < m) {
		cout << "NO" << endl;
		return 0;
	}
	vector<int>limits(n), reserve(m);
	for (int i = 0; i < n; i++)cin >> limits[i];
	for (int j = 0; j < m; j++)cin >> reserve[j];
	sort(limits.begin(), limits.end(),greater<int>());
	sort(reserve.begin(), reserve.end(),greater<int>());
	bool f = true;
	for (int i = 0; i < m; i++) {
		if (limits[i] < reserve[i])f = false;
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}