#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main() {
	string a, b;
	int i, f;
	while (cin >> a >> b) {
		string c;
		f = a.find('_') + 1;
		for (i = f; i < a.size(); ++i) {
			c += a[i];	
		}
		c += "_small_";
		f = b.find('_') + 1;
		for (i = f; i < b.size(); ++i) {
			 c += b[i];	
		}
		cout << c << endl;
	}
	return 0;
}
