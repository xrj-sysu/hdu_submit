#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int vis[25];
int a[25];
int p[40] = {0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
void dfs(int m) {
	int i;
	if (m == n && p[a[m-1]+a[0]]) {
		for (i = 0; i < m - 1; ++i) {
			printf("%d ", a[i]);
		}
		printf("%d\n", a[m-1]);
	} else {
	      for (i = 2; i <= n; ++i) {
	      	  if (!vis[i]) {
	      	  	  if (p[i+a[m-1]]) {
	      	  	  	  vis[i] = 1;
	      	  	  	  a[m++] = i;
	      	  	  	  dfs(m);
	      	  	  	  vis[i] = 0;
	      	  	  	  m--;
	      	  	  } 
	      	  }
	      }	
	  }
}
int main() {
	int num = 1;
	while(scanf("%d", &n) != EOF) {
	    memset(vis, 0, sizeof vis);
	    printf("Case %d:\n", num);
	    a[0] = 1;
	    dfs(1);
	    printf("\n");
	    num++;
	}
	return 0;
}
