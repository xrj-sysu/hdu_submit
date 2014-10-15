#include<iostream>
#include<queue>
using namespace std;
int main() {
    int n, k, value;
    char type;
    while (cin >> n >> k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        while (n--) {
            cin >> type;
            if (type == 'I') {
                cin >> value;
                if (pq.size() < k) {
                    pq.push(value);
                }
                else if (value > pq.top()) {
                    pq.pop();
                    pq.push(value);
                }
            }
            if (type == 'Q') {
                cout << pq.top() << endl;     
            }
        }
    }
    return 0; 
}
