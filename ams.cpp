#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    long long c1 = 0, c2 = 0, c3 = 0;
    for (char c : s) {
        if (c == 'A') {
            c1++;
        } else if (c == 'M') {
            c2 += c1;
        } else if (c == 'S') {
            c3 += c2;
        }
        //cerr << c1 << ' ' << c2 << ' ' << c3 <<'\n';
    }
    
    cout << c3 << endl;
    return 0;
}
