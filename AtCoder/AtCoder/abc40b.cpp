#include<iostream>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL


int main() {
	int n,wa=1000000;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i*j <= n; j++) {
			if ((abs(i - j) + (n - i*j)) < wa)wa = (abs(i - j) + (n - i*j));
		}
	}
	cout << wa << endl;
	return 0;

}