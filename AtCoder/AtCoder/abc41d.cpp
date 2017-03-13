#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	vector<int>x(m), y(m);
	for (int i = 0; i < m; i++)cin >> x[i] >> y[i];
	vector<int>result;
	for (int i = 1; i <= n; i++) {
		result.push_back(i);
	}
	long long cnt = 0;
	do {
		int f = 0;
		for (int i = 0; i < m; i++) {
			if (!(find(result.begin(), result.end(), x[i]) < find(result.begin(), result.end(), y[i]))) { f = 1; break; }
		}
		if (!f)cnt++;
	} while (next_permutation(result.begin(), result.end()));

	cout << cnt << endl;
	return 0;
}
