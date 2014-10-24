#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000005];
bool cmp(int x, int y) {
    if (x >= y) {
        return true; 
    } else {
          return false;    
      }
}
int main() {
    int n, m, i;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n, cmp);
        for (i = 0; i < m-1; ++i) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[i]);
    }
    return 0;
}
