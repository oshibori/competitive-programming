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
	int n; cin >> n;
	while (n--) {
		string big, small;
		cin >> big >> small;
		if (small.size() > big.size())swap(big, small);
		reverse(big.begin(), big.end());
		reverse(small.begin(), small.end());
		//cout << "reverse" << endl << s1 << endl << s2 << endl;
		vector<int>vb(big.size()), vs(small.size());
		for (int i = 0; i < big.size(); i++)vb[i] = big[i] - '0';
		for (int i = 0; i < small.size(); i++)vs[i] = small[i] - '0';
		for (int i = 0; i < small.size(); i++) vb[i] += vs[i];
		for (int i = 0; i < big.size(); i++) {
			if (vb[i] >= 10) {
				vb[i] -= 10;
				if (i == big.size() - 1)vb.push_back(1);
				else vb[i + 1]++;
			}
		}
		if (vb.size() > 80)cout << "overflow" ;
		else for (int i = 0; i < vb.size(); i++) {
			cout << vb[vb.size() - 1 - i];
		}
		cout << endl;
	}
	return 0;
}