#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char s[(int) 1e6];
    cin >> s;
    long long count = 0, ans = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == ')' and s[i + 1] == ')') {
            count += 1;
        }
    }
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '(' and s[i + 1] == '(') {
            ans += count;
        } else {
            if(s[i] == ')' and s[i + 1] == ')') {
                count--;
            }
        }
    }
    cout << ans;
}