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


int hantei() {
	
}

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> b(h),a(h);
	for (int i = 0; i < h; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (b[i][j] == '#') {
				if (i == 0) {
					if (j == 0) {
						if ((b[0][1] == '#' || b[1][0] == '#' || b[1][1] == '#') && (b[0][1] == '.' || b[1][0] == '.' || b[1][1] == '.'))a[0][0] = '.';

					}
					else if (0 < j&&j < w - 1) {
						if()
					}
					else if (j == w - 1) {
						if ((b[0][w - 2] == '#' || b[1][w - 2] == '#' || b[1][w - 1] == '#') && (b[0][w - 2] == '.' || b[1][w - 2] == '.' || b[1][w - 1] == '.'))a[0][w - 1] = '.';
					}
				}
			}
		}
	}
	return 0;
}