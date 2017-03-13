#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<list>
using namespace std;
static string s;
int main() {
	int k;
	/*cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] += 1;
	}
	cout << s << endl;*/
	cin >> s >> k;
	for (int i = 0; i < s.size()&&0<k; i++) {
		//if (s[i] == 'a')continue;
		if ('z'+1 - s[i] <= k&&s[i]!='a') {
			k -= ('z'+1 - s[i]);
			s[i] ='a';
			//cout << s[i] << "¨ a   k =" << k << endl;
		}
		if (i == s.size() - 1) {
			s[i] += (k%26);
		}
	}
	cout << s << endl;

	return 0;
}