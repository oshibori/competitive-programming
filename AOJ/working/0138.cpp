#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
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
#include<complex>
#define EPS 1e-10
using namespace std;
typedef long long llong;
bool f(pair<int, double>a, pair<int, double>b) {
	return a.second < b.second;
}
int main() {
	vector<pair<int, double> >v(24);
	for (int i = 0; i < 24; i++) {
		cin >> v[i].first >> v[i].second;
	}
	//cout << endl << endl;
	//cout << setprecision(4);
	sort(v.begin(), v.begin() + 8, f);
	cout << v[0].first << " " << v[0].second << endl;
	cout << v[1].first << " " << v[1].second << endl;

	sort(v.begin() + 8, v.begin() + 8 + 8, f);
	cout << v[8].first << " " << v[8].second << endl;
	cout << v[9].first << " " << v[9].second << endl;

	sort(v.begin() + 8 + 8, v.end(), f);
	cout << v[16].first << " " << v[16].second << endl;
	cout << v[17].first << " " << v[17].second << endl;

	v.erase(v.begin() + 8 + 8, v.begin() + 8 + 8 + 2);
	v.erase(v.begin() + 8, v.begin() + 8 + 2);
	v.erase(v.begin(), v.begin() + 2);

	sort(v.begin(), v.end(), f);
	cout << v[0].first << " " << v[0].second << endl;
	cout << v[1].first << " " << v[1].second << endl;

	return 0;
}