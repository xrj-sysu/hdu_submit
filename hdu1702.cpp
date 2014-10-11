#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
int main() {
	int t, n, i, data;
	string word, op;
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> word;
		if (word == "FIFO") {
			queue<int> q;
			for (i = 0; i < n; ++i) {
				cin >> op;
				if (op == "IN") {
					cin >> data;
					q.push(data);
				}
				if (op == "OUT") {
					if (!q.empty()) {
						cout << q.front() << endl;
						q.pop();
					} else {
					      cout << "None" << endl;	
					  }
				}
			}
		}
		if (word == "FILO") {
			stack<int> s;
			for (i = 0; i < n; ++i) {
				cin >> op;
				if (op == "IN") {
					cin >> data;
					s.push(data);
				}
				if (op == "OUT") {
					if (!s.empty()) {
						cout << s.top() << endl;
						s.pop();
					} else {
					      cout << "None" << endl;	
					  }
				}
			}
		}
	}
	return 0;
}
