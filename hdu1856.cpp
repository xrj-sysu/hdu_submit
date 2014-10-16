#include<iostream>
#include<cstdio>
using namespace std;

// num represent the rank of the node
// pay attention to the n == 1
// to avoid TLE, not to travel through all 10000000 

struct A {
	int num;
	int pre;
}a[10000005];

void init(int n) {
	for (int i = 1; i <= n; ++i) {
		a[i].num = 1;
		a[i].pre = i;
	}
}
int find(int x) {
	if (a[x].pre == x) {
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
	int n, s, t, i, ans, max;
	int p[100005], q[100005];
	while (scanf("%d", &n) != EOF) {
		max = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d%d", &p[i], &q[i]);
			if (p[i] > max) max = p[i];
			if (q[i] > max) max = q[i];
		}
		init(max);
		for (i = 0; i < n; ++i) {
			merge(p[i], q[i]);
		}
		ans = 0;
		for (i = 1; i <= max; ++i) {
			if (a[i].num > ans) {
				ans = a[i].num;
			}
		}
		if (n == 0) printf("1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
