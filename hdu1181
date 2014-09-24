#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int adj[30][30];
int flag;
int visit[30];
void dfs(int u) {
    if (flag == 1) {
        return;
    }
    if (u == 12) {
        flag = 1;
        return;
    } else {
          for (int i = 0; i < 30; ++i) {
              if (adj[u][i] == 1) {
                  adj[u][i] = 0;
                  dfs(i);
                  adj[u][i] = 1;
              }
          }  
      }
}
int main() {
    string s;
    int x, y;
    while (cin >> s) {
        if (s == "0") {
            continue;
        }
        flag = 0;
        memset(adj, 0, sizeof adj);
        x = s[0] - 'a';
        y = s[s.size() - 1] - 'a';
        adj[x][y] = 1;
        while (cin >> s && s != "0") {
            x = s[0] - 'a';
            y = s[s.size() - 1] - 'a';
            adj[x][y] = 1;
        }
        // memset(visit, 0, sizeof visit);
        dfs(1);
        if (flag == 1) {
            cout << "Yes." << endl;
        } else {
              cout << "No." << endl; 
          } 
    }
    return 0;
}
