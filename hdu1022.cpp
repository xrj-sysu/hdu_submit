#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	int n, i, j, num;
	int flag[20];
	string a, b;
	while (cin >> n) {
		cin >> a >> b;
		stack<char> s;
		i = 0;
		j = 0;
		num = 0;
		while (j < n) {
			if (s.empty() || (s.top() != b[j] && i < n)) {
				s.push(a[i]);
				i++;
				flag[num++] = 1;
			} else {
			      if (s.top() == b[j]) {
			      	  s.pop();
			      	  j++;
			      	  flag[num++] = 0;
			      }	else {
			      	    break;
			        }
			  }
		}
		if (!s.empty()) {
				cout << "No." << endl;
		} else {
			  cout << "Yes." << endl;
			  for (i = 0; i < num; ++i) {
			      if (flag[i] == 1) {
			      	  cout << "in" << endl;
			      } else {
			      	    cout << "out" << endl;
			      	}
			  }	
		  }
		cout << "FINISH" << endl;
	}
	return 0;
}
