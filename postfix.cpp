#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string exp;
    
    while (getline(cin, exp)) {
        stack<int> s;
        stringstream ss(exp);
        string t;
        
        while (ss >> t) {
            if (isdigit(t[0])) {
                s.push(stoi(t));
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                
                if (t == "+") {
                    s.push(a + b);
                } else if (t == "-") {
                    s.push(a - b);
                } else if (t == "*") {
                    s.push(a * b);
                }
            }
        }
        
        cout << s.top() << endl;
    }
    
    return 0;
}
