#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int To = ceil((double)(1LL * Z * (X - Y)) / Y);

    cout << To << endl;
    return 0;
}
