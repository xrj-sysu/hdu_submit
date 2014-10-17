#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

// scanf/printf is recommended since TLE occurs using cin/cout

struct node {
    int pre;
    int num;
}a[200005]; 
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        a[i].pre = i;
        a[i].num = 1;
    }
}
int find(int x) {
    if (x == a[x].pre) {
        return x;
    } else {
          a[x].pre = find(a[x].pre);
          return a[x].pre;    
      }
}
void merge(int m, int n) {
    int x = find(m);
    int y = find(n);
    if (x == y) {
        return;
    } else {
          a[x].pre = y;
          a[y].num += a[x].num;
      }
}
int main() {
    int n, f, k;
    char s[25], t[25];
    while (scanf("%d", &n) != EOF) {
        while (n--) {
            k = 0;
            scanf("%d", &f);
            init(2 * f);
            map<string, int> m;
            while (f--) {
                scanf("%s%s", s, t);
                if (!m[s]) {
                    m[s] = ++k;
                }
                if (!m[t]) {
                    m[t] = ++k;
                }
                merge(m[s], m[t]);
                int ans = a[find(m[s])].num;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
