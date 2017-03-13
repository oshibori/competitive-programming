#include<iostream>
#include<vector>
using namespace std;
class People {
public:
	int m;
	bool f = false;
	vector<int>p;
	People() {
		cin >> m;
		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			p.push_back(t);
		}
	}
};
int main() {
	int n;
	while (cin >> n&&n) {
		vector<People>x(n);
		vector<People>k;
		
	}
	return 0;
}