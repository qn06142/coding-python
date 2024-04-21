#include<iostream>
#include<string.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int luckynums;
    for(auto i:s) {
        luckynums += (i == '4' or i =='7');
    }
    string s1 = to_string(luckynums);
    luckynums = 0;
    for(auto i:s1) {
        luckynums += (i == '4' or i == '7');
    }
    if(luckynums == s1.length()) {
        cout << "YES";
    } else cout << "NO";
}