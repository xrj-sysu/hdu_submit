#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int dis[500005];
int INF = 0x7ffffff;
int l, n, m;

// the function is to check whether is ok for ability x
bool is_ok(int x) {
	int cnt = 0;
	int num = 0;
	int i = 0;
	while (num < l) {
		num += x;
		while (num >= dis[i+1]) {
			i++;
		}
		num = dis[i];
		cnt++;
	}
	if (cnt > m) {
		return false;
	} else {
	      return true;	
	  }
}

int main() {
	int i, left, right, mid, max;
	while (scanf("%d%d%d", &l, &n, &m) != EOF) {
		dis[0] = 0;
		for (i = 1; i <= n; ++i) {
			scanf("%d", &dis[i]);
		}
		dis[n+1] = l;
		dis[n+2] = INF;
		sort(dis, dis + n + 2);
		max = 0;
		for (i = 1; i <= n + 1; ++i) {
			if (dis[i] - dis[i-1] > max) {
				max = dis[i] - dis[i-1];
			}
		}
		left = max;
		right = l;
		while (left <= right) {
		    mid = (left + right) >> 1;
		    if (is_ok(mid)) {
		    	right = mid - 1;
		    } else {
		    	  left = mid + 1;
		      }
		}
		printf("%d\n", left);
	}
	return 0;
}
