#include <iostream>
#include <string>
using namespace std;

char shiftChar(char c, int n) {

    n = n % 26;

    if (isupper(c)) {

        return 'A' + (c - 'A' + n + 26) % 26;
    } else if (islower(c)) {

        return 'a' + (c - 'a' + n + 26) % 26;
    } else {

        return c;
    }
}

int main() {
    string message;
    int n;

    getline(cin, message);

    cin >> n;

    for (char &c : message) {
        c = shiftChar(c, n);
    }

    cout << message << endl;

    return 0;
}