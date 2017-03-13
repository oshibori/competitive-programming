#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<cctype>
#include<stack>
#include<queue>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long llong;
int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (islower(s[i]))s[i]=toupper(s[i]);
	}
	cout << s << endl;
	return 0;
}