#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<double>h;
	double x;
	while (cin >> x) {
		h.push_back(x);
	}
	cout << *max_element(h.begin(), h.end()) - *min_element(h.begin(), h.end()) << endl;
	return 0;
}