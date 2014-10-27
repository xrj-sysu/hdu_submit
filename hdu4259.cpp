#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int a[805][805];
int b[805];
int vis[805];

long long gcd(long long x, long long y) {
	return x ? gcd(y % x, x) : y;
}

int main() {
	int n, k, i, j, cnt, t, m;
	while (scanf("%d%d", &n, &k) != EOF) {
		if (n == 0 && k == 0) {
			break;
		}
		cnt = 1;
		for (i = 0; ; ++i) {
			for (j = 0; j < k; ++j) {
				a[i][j] = cnt++;
			}
			if (cnt > n) {
				break;
			}
		}
		cnt = 1;
		for (j = 0; j < k; ++j) {
			for (m = i; m >= 0; m--) {
				if (a[m][j] <= n && a[m][j]) {
				    b[cnt++] = a[m][j];
			    }
			}
		}
		memset(vis, 0, sizeof vis);
		long long ans = 1, len;
		for (i = 1; i <= n; ++i) {
			if (!vis[i]) {
				len = 0;
				t = i;
				while (1) {
					if (vis[t]) {
						break;
					}
					len++;
					vis[t] = 1;
					t = b[t];
				}
			}
			ans = ans / gcd(len, ans) * len;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
