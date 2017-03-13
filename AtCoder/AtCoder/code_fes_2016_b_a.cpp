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
#include<cctype>
#include<map>
using namespace std;
typedef long long llong;
int main() {
	string s;
	int cnt = 0;
	cin >> s;
	string b = "CODEFESTIVAL2016";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != b[i])cnt++;
	}
	cout << cnt << endl;
	return 0;
}