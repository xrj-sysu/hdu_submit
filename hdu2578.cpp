#include<iostream>
#include<cstdio>
#include<algorithm> // 原来这里面就有binary_search 
using namespace std;
int a[100005];
int main() {
    int t, k, n, i, count, ser, left, right, mid;
    scanf("%d", &t);
    while (t--) {
        count = 0;
        scanf("%d%d", &n, &k);
        for (i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (i = 0; i < n; ++i) {
            ser = k - a[i];
            left = 0;
            right = n - 1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (a[mid] == ser) {
                    count++;
					// 之前这一点没考虑，一直WA 
					if (i != 0 && a[i] == a[i-1]) {
            		    count--;
            	    }
                    break;
                } else if (a[mid] > ser){
                      right = mid - 1;
                  } else {
                          left = mid + 1;
                    }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
