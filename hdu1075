#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node {
    int next[26];
    char eng[15];
    void init() {
        memset(next, -1, sizeof next);
    }
}T[1000005]; 
int le;
void insert(char* c1, char* c2) {
    int i, x;
    int p = 0;
    for (i = 0, p = 0; i < strlen(c2); ++i) {
        x = c2[i] - 'a';
        if (T[p].next[x] == -1) {
            T[le].init();
            T[p].next[x] = le++;
        }
        p = T[p].next[x];
    }
    strcpy(T[p].eng, c1);
}
void query(char* c2) {
    int i, x;
    int p = 0;
    for (i = 0, p = 0; i < strlen(c2); ++i) {
        x = c2[i] - 'a';
        if (T[p].next[x] == -1) {
            printf("%s", c2);
            return;
        }
        p = T[p].next[x];
    }
    // 注意某个不存在单词可能是另一个已存在单词的前缀 
    if (strlen(T[p].eng) == 0) {
        printf("%s", c2);
    } else {
          printf("%s", T[p].eng);
      }
}
int main() {
    char start[15], slate[3005], c1[15], c2[15], temp[35];
    int len, i, num;
    scanf("%s", start);
    T[0].init();
    le = 1;
    while(scanf("%s", c1)) {
        if (strcmp(c1, "END") == 0) {
            break;
        }
        scanf("%s", c2);
        insert(c1, c2);
    }
    scanf("%s", start);
    getchar();
    while(gets(slate)) {
        if (strcmp(slate, "END") == 0) {
            break;
        }
        len = strlen(slate);
        num = 0;
        memset(temp, '\0', sizeof temp);
        for (i = 0; i < len; ++i) {
            if (slate[i] >= 'a' && slate[i] <= 'z') {
                temp[num++] = slate[i];
            } else {
                  if (num > 0) {
                      query(temp);
                  }
                  printf("%c", slate[i]);
                  num = 0;
                  memset(temp, '\0', sizeof temp);
              }
        }
        if (num > 0) {
            query(temp);
        }
        printf("\n");
    } 
    return 0;    
}
