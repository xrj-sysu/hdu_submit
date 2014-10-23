#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int n, m;
char a[1005];
int f[1005][40];
int num[1005];
int ans[1005];

void RMQ_ST() {
    int i, j, p, q;
    int temp = (int)(log((double)n)/log(2.0));
    for (i = 0; i < n; ++i) {
        f[i][0] = i;
    }
    for (j = 1; j <= temp; ++j) {
        for (i = 0; i+(1<<j)-1 < n; ++i) {
             p = f[i][j-1];
             q = f[i+(1<<(j-1))][j-1];
             if (num[p] <= num[q]) {
                 f[i][j] = p; 
             } else {
                  f[i][j] = q;
               }
        }
    }
}
int query(int l, int r) {
    int temp = (int)(log((double)(r-l+1))/log(2.0));
    int p = f[l][temp];
    int q = f[r-(1<<temp)+1][temp];
    if (num[p] <= num[q]) {
        return p;
    } else {
          return q;
      }
}

int main() {
    int i, len, j;
    while (scanf("%s%d", a, &m) != EOF) {
        n = strlen(a);
        for (i = 0; i < n; ++i) {
            num[i] = a[i] - '0'; 
        }
        m = n - m;
        RMQ_ST();
        i = 0;
        j = 0;
        while (m--) {
            i = query(i, n - m);
            ans[j++] = num[i++];
        }
        for (i = 0; i < j; ++i) {
            if (ans[i] != 0) {
                break;
            }
        }
        if (i == j) {
            printf("0\n");
            continue;
        }
        while (i < j) {
            printf("%d", ans[i++]);
        }
        printf("\n");
    }
    return 0;
}
