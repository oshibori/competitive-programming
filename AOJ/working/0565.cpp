#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int>pasta(3), juce(2);
	for (int i = 0; i < 3; i++)cin >> pasta[i];
	for (int i = 0; i < 2; i++)cin >> juce[i];
	cout << *min_element(pasta.begin(), pasta.end()) + min(juce[0], juce[1]) - 50 << endl;
	return 0;
}