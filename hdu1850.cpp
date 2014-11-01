#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
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
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
