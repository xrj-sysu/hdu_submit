#include<iostream>
using namespace std;
int a[1001];
int b[1001];
void post_order(int pre, int in, int len, int flag) {
    if (len == 1) {
        cout << a[pre] << " ";
    } else if(len == 0) {
      
      } else {
          int le = 0, i;
          for (i = in; b[i] != a[pre]; ++i) {
              le++;
          }
          post_order(pre+1, in, le, 0);
          post_order(pre+le+1, i+1, len-le-1, 0);
          if (flag == 1) {
              cout << a[pre];
          } else {
                cout << a[pre] << " ";
            }
        }
}
int main() {
    int n, i;
    while (cin >> n) {
        for (i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (i = 0; i < n; ++i) {
            cin >> b[i];
        }
        post_order(0, 0, n, 1);
        cout << endl;
    }
    return 0;
}
