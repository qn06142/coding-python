#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    cout << ((y == 2) ? (3 - x) * 2 : 3 - x + 1);
}