#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<sstream>
using namespace std;

string query[31] = {"00001", "00010", "00011", "00100", "00101", "00110",
                    "00111", "01000", "01001", "01010", "01011", "01100",
					"01101", "01110", "01111", "10000", "10001", "10010",
					"10011", "10100", "10101", "10110", "10111", "11000",
					"11001", "11010", "11011", "11100", "11101", "11110",
					"11111"};
int main() {
	int flag, i;
	string op, order;
	string lo;
	while (cin >> flag) {
		if (flag) {
			cin >> op;
			cin >> order;
			string a;
			string b;
			int x = 0, y = 0;
			int f = order.find(',');
			if (order != "SET") {
		        for (i = 0; i < f; ++i) {
				    a += order[i];
			    }
		    }
			for (i = f + 1; i < order.size(); ++i) {
				b += order[i];
			}
			if (op != "SET") {
			    for (i = 1; i < a.size(); ++i) {
				    x = x * 10 + a[i] - '0';
		     	}
		    }
			for (i = 1; i < b.size(); ++i) {
				y = y * 10 + b[i] - '0';
			}
			string ans;
			if (op == "ADD") {
				ans += "000001";
			}
			if (op == "SUB") {
				ans += "000010";
			}
			if (op == "DIV") {
				ans += "000011";
			}
			if (op == "MUL") {
				ans += "000100";
			}
			if (op == "MOVE") {
				ans += "000101";
			}
			if (op == "SET") {
				ans += "000110";
			}
			if (op != "SET") {
			    ans += query[x-1];
		    }
			ans += query[y-1];
			if (op == "SET") {
				ans += "00000";
			}
			cout << ans << endl;
		}
		if (!flag) {
			cin >> lo;
			int sign;
			string ans;
			string p, q, r;
			p = lo.substr(0, 6);
			q = lo.substr(6, 5);
			r = lo.substr(11, 5);
			if (p == "000001") {
				ans += "ADD";
			}
			else if (p == "000010") {
				ans += "SUB";
			}
			else if (p == "000011") {
				ans += "DIV";
			}
			else if (p == "000100") {
				ans += "MUL";
			}
			else if (p == "000101") {
				ans += "MOVE";
			}
			else if (p == "000110") {
				ans += "SET";
			} 
			else {
				cout << "Error!" << endl;
				continue;
			}
			for (i = 0; i < 31; ++i) {
				if (query[i] == q) {
				    break;
			    }
			}
			if (i == 31) {
				cout << "Error!" << endl;
				continue;
			} else {
				  stringstream ss;
				  i++;
				  ss << i;
			      ans = ans + " R" + ss.str();	
			  } 
			if (p == "000110") {
				if (r == "00000") {
					cout << ans << endl; 
				} else {
				      cout << "Error!" << endl;	
				  }
				continue;
			}
			for (i = 0; i < 31; ++i) {
				if (query[i] == r) {
				    break;
			    }
			}
			if (i == 31) {
				cout << "Error!" << endl;
				continue;
			} else {
				  stringstream st;
				  i++;
				  st << i;
			      ans = ans + ",R" + st.str();	
			  }
			cout << ans << endl;
		}
	}
	return 0;
}
