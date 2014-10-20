#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[505];
int b[505];
int c[505];
__int64 d[250005];

int main() {
	int l, n, m, i, j, k, s, flag, que, ans, left, right, mid;
	int count = 1;
	while (scanf("%d%d%d", &l, &n, &m) != EOF) {
		for (i = 0; i < l; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d", &b[i]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%d", &c[i]);
		}
		k = 0;
		for (i = 0; i < l; ++i) {
			for (j = 0; j < n; ++j) {
				d[k++] = a[i] + b[j];
			}
		}
		sort(d, d + k);
		scanf("%d", &s);
		printf("Case %d:\n", count++);
		for (i = 0; i < s; ++i) {
			scanf("%d", &que);
			flag = 0;
			for (j = 0; j < m; ++j) {
				ans = que - c[j];
				left = 0;
				right = k - 1;
				while (left <= right) {
					mid = (left + right) >> 1;
					if (d[mid] == ans) {
						flag = 1;
						break;
					} else if (d[mid] < ans) {
					      left = mid + 1;	
					  } else {
					  	    right = mid - 1;
					    }
				}
				if (d[left] == ans) {
					flag = 1;
				}
				if (flag) {
					printf("YES\n");
					break;
				}
			}
			if (flag == 0) {
				printf("NO\n");
			}
		}
	}
	return 0;
}
