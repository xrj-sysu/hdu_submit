#include<iostream>
using namespace std;
int main() {
	string t;
	while (cin >> t) {
		int ans = 0;
		for (int i = 0; i < t.size() && t[i] != 'B'; ++i) {
			if (t[i] == '(') {
				ans++;
			}
			if (t[i] == ')') {
				ans--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
