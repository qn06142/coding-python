#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int x_rotated = x + y;
    int y_rotated = y - x;

    cout << "Rotated point: (" << x_rotated << ", " << y_rotated << ")\n";
    return 0;
}
