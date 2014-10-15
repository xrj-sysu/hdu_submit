#include<iostream>
#include<queue>
#include<string>
using namespace std;
class node {
    public:
    	node(string _meg, int _value, int _pri, int _num) {
    		meg = _meg;
    		value = _value;
    		pri = _pri;
    		num = _num;
    	}
		bool operator<(const node& other) const {
		    if (pri == other.pri) {
		    	return num > other.num;
		    }
			return pri > other.pri; 
	    } 
	    string meg;
        int value;
        int pri;
        int num;
};
int main() {
	string type, meg;
	priority_queue<node> pq;
	int value, pri;
	int num = 0;
	while (cin >> type) {
		if (type == "GET") {
			if (pq.empty()) {
				cout << "EMPTY QUEUE!" << endl;
			} else {
			      node temp = pq.top();
				  cout << temp.meg << " " << temp.value << endl;
				  pq.pop();	
			  }
		}
		else if (type == "PUT") {
			cin >> meg;
			cin >> value >> pri;
			node n(meg, value, pri, num);
			num++;
			pq.push(n);
		}
	}
	return 0;
}
