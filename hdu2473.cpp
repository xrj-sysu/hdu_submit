#include<iostream>
#include<set>
#include<cstdio>
using namespace std;

// 题目给的n的大小是骗人的
// the key is to open the b array. I have tried add a new value but failed.

int a[1000005];
int b[1000005];
void init(int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i;
        b[i] = i;
    }
}
int find(int x) {
    if (x == a[x]) {
        return x;
    } else {
          a[x] = find(a[x]);
          return a[x];    
      }
}
void merge(int m, int n) {
    int x = find(m);
    int y = find(n);
    if (x == y) {
        return;
    } else {
          a[x] = y;    
      }
}
int main() {
    int n, m, p, q, i, ans, temp;
    char c;
    int count = 0; 
    while (scanf("%d%d", &n, &m)) {
        count++;
        if (n == 0 && m == 0) {
            break;
        }
        init(n);
        ans = 0;
        temp = n;
        while (m--) {
            getchar();
			scanf("%c", &c);
            if (c == 'M') {
                scanf("%d%d", &p, &q);
                merge(b[p], b[q]);
            }
            if (c == 'S') {
                scanf("%d", &p);
                b[p] = temp;
                a[temp] = temp;
                temp++;
            }
        }
        set<int> myset;
        for (i = 0; i < n; ++i) {
		    myset.insert(find(b[i]));
        }
        ans = myset.size();
        printf("Case #%d: %d\n", count, ans);
    }
    return 0;
}
