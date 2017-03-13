#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main() {
	int n, m;double p;
	while (cin >> n >> m >> p&&n&&m) {
		//p /= 100;
		vector<int> x;
		int cnt = 0,y;
		for (int i = 0; i < n; i++) {
			cin >> y;
			x.push_back(y);
		}
		double money = 100*accumulate(x.begin(), x.end(), 0);
		money = money*(100 - p);
		if (x[m-1]==0)cout << 0 << endl;
		else cout << (int)(money / (double)x[m-1]/100.0) << endl;
	}
	return 0;
}
