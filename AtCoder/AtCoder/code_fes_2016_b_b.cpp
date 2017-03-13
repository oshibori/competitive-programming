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
	int N, A, B,cnt=0,fcnt=0;
	string s;
	cin >> N >> A >> B;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'c')cout << "No" << endl;
		else if (s[i] == 'a'&&cnt < A + B) {
			cout << "Yes" << endl;
			cnt++;
		}
		else if (s[i] == 'b'&&cnt < A + B&&fcnt < B) {
			cout << "Yes" << endl;
			cnt++;
			fcnt++;
		}
		else cout << "No" << endl;
	}
	
	return 0;
}