#include <iostream>
#include <string>
using namespace std;
int main() {
    string SS, XX;
    cin >> SS >> XX;

    int count = 0;
    size_t pos = 0;

    while ((pos = SS.find(XX, pos)) != string::npos) {
        count++;
        pos += XX.length();
    }

    cout << count << endl;
    return 0;
}