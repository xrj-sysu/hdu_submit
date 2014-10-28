#include<iostream>
#include<cstdio>
using namespace std;

// I learned Josephus Problem from a super big god
// http://maskray.me/blog/2013-08-27-josephus-problem-two-log-n-solutions

int main() {
	int n, m, ans, i;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) {
			break;
		}
		ans = 0;
		for (i = 2; i <=n; ++i) {
			ans = (ans + m) % i;
		}
		printf("%d %d %d\n", n, m, ans+1);
	}
	return 0;
}
