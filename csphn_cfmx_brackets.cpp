#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isopen[255];
bool isclose[255];
char oppo[255];

bool check(string x) {
    stack<char> stor;
    for (char c : x) {
        if (isopen[c]) {
            stor.push(c);
        } else if (isclose[c]) {
            if (stor.empty()) return false;
            if (stor.top() != oppo[c]) return false;
            stor.pop();
        }
    }
    return stor.empty();
}

int main() {
    isopen['{'] = isopen['('] = isopen['['] = true;
    isclose[')'] = isclose['}'] = isclose[']'] = true;
    oppo['['] = ']';
    oppo[']'] = '[';
    oppo['{'] = '}';
    oppo['}'] = '{';
    oppo['('] = ')';
    oppo[')'] = '(';
    string s;
    cin >> s;
    s = s + s;
    for(int i = 0; i < s.size() / 2; i++) {
        if(check(s.substr(i, s.size() / 2))) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
