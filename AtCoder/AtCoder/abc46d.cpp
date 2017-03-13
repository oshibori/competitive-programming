#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin >> s;
	cout << (s.size() - 2 * count(s.begin(), s.end(), 'p')) / 2 << endl;
	return 0;
}