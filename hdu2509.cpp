#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n, i;
	int sum, num;
	int a[105];
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		num = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum ^= a[i];
		    if (a[i] >= 2) {
		    	num++;
		    }
		}
		if (num == 0) {
			if (n % 2 == 1) {
				printf("No\n");
			} else {
				printf("Yes\n");
			}
		} else {
			if (sum == 0) {
				printf("No\n");
			} else {
				printf("Yes\n");
			}
		}
	}
	return 0;
}
