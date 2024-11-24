#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'y') {
            i += 1;
        }
        cout << s[i];
    }
}