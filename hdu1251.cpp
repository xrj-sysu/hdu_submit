#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node {
    int next[26];
    int cnt;
    void init() {
        cnt = 0;
        memset(next, -1, sizeof next);
    }
}T[1000001];
int le;
void insert(string s) {
    int i, x;
    int p = 0;
    for (i = 0; i < s.size(); ++i) {
        x = s[i] - 'a';
        if (T[p].next[x] == -1) {
            T[le].init();
            T[p].next[x] = le;
            le++;
        }
        p = T[p].next[x];
        T[p].cnt++;
    }
}
int query(string s) {
    int i, x;
    int p = 0;
    for (i = 0; i < s.size(); ++i) {
        x = s[i] - 'a';
        if (T[p].next[x] == -1) {
            return 0;
        }
        p = T[p].next[x];
    }
    return T[p].cnt;
}
int main() {
    string s, t;
    T[0].init();
    le = 1;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        insert(s);
    }
    while (cin >> t) {
        cout << query(t) << endl;
    }
    return 0;
}
