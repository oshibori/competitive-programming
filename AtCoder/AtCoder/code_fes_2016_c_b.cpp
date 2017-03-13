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
	int k, t;
	cin >> k >> t;
	vector<int>a(t);
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}
	if (t == 1) {
		cout << k - t << endl;
		return 0;
	}
	auto it = max_element(a.begin(), a.end());
	int index = distance(a.begin(),max_element(a.begin(), a.end()));
	(*it)--;
	//cout << "index is " << index << endl;
	//for (int i = 0; i < t; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	for (int cnt = 1; cnt < k; cnt++) {
		int max = -(1<<21);
		int p ;
		
		for (int i = 0; i < t; i++) {
			if (i == index)continue;
			if (max < a[i]) {
				max = a[i];
				p = i;
			}
		}
		//cout << "index is " << index << endl;
		a[p]--;
		index = p;
		bool f = true;
		for (int i = 0; i < t; i++) {
			if (i == p)continue;
			if (a[i] != 0)f = false;
		}
		if (f)break;
		//for (int i = 0; i < t; i++) {
		//	cout << a[i] << " ";
		//}
		//cout << endl;
		
	}
	//for (int i = 0; i < t; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << endl;
	cout << *max_element(a.begin(), a.end())  << endl;
	//int max = *max_element(a.begin(), a.end());
	//vector<int>::iterator it = max_element(a.begin(), a.end());
	//(*it)--;
	//int x = 0;
	//for (int cnt = 1; cnt < k; cnt++) {
	//	auto g = max_element(a.begin(), it);
	//	auto h = max_element(it + 1, a.end());
	//	if (*h == 0 && *g == 0)break;
	//	if (*g > *h) {
	//		(*g)--;
	//		it = g;
	//	}
	//	else {
	//		(*h)--;
	//		it = h;
	//	}
	//}
	//cout << *max_element(a.begin(), a.end()) << endl;
	return 0;
}