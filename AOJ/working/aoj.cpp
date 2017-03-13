#include<cmath>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<string>
using namespace std;



int main() {
	char s[11],r[22],rc[22];
	int n,cnt=0;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		
		cin >> r;

		strcpy(rc, r);
		strcat(r, rc);
		if (strstr(r, s) != NULL)cnt++;
	}
	cout << cnt << endl;
	
	return 0;
}

