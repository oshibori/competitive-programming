#include<cmath>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;

int main() {
	char s[101];
	int f=0,cnt=0;
	while (cin>>s) {
		f = 0;
		for (int i = 0; i <= (strlen(s))/2; i++) {
			if (s[i] != s[(strlen(s) - 1) - i]) {
				f = 1; break;
			}
			
		}
		if (f == 0)cnt++;

	}
	cout << cnt << endl;
	return 0;

}