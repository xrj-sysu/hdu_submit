#include<iostream>
#include<cstdio>
using namespace std;
int a[200005];
int b[200005][2];
int main() {
	int n, i, ans;
	int sum;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			break;
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum = sum ^ a[i];
		}
		ans = 0;
		for (i = 0; i < n; ++i) {
			if (a[i] > (sum ^ a[i])) {
				b[ans][0] = a[i];
				b[ans][1] = (sum ^ a[i]);
				ans++;
			}
		}
		if (sum == 0) {
			printf("No\n");
		} else {
			printf("Yes\n");
			for (i = 0; i < ans; ++i) {
				printf("%d %d\n", b[i][0], b[i][1]);
			}
		}
	}
	return 0;
}
