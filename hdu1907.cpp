#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int t, n, i;
	int a[50];
	int sum;
	int num;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		num = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum ^= a[i];
			if (a[i] >= 2) {
				num++;
			}
		}
		if (num == 0) {
			if (n % 2 == 1) {
				printf("Brother\n");
			} else {
				printf("John\n");
			}
		} else {
			if (sum == 0) {
				printf("Brother\n");
			} else {
				printf("John\n");
			}
		}
	}
	return 0;
}
