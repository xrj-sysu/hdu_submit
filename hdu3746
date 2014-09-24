#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int next[100005];
void make_next(string s) {
    int len = s.size();
    int k, i;
    next[0] = 0;
    for (i = 1, k = 0; i < len; ++i) {
        while (k > 0 && s[i] != s[k]) {
            k = next[k-1];
        }
        if (s[i] == s[k]) {
            k++;
        }
        next[i] = k;
    }
}
int main() {
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        make_next(s);
        int len = s.size();
        int ans = len - next[len-1];
        if(ans!=len && len%ans == 0)  
        cout << 0 << endl;  
        else  
        cout << ans-next[len-1]%ans << endl; 
    }
    return 0;
}
