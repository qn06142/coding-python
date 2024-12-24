#include <iostream>
using namespace std;

int main() {
    long long S1, V1, S2, V2;
    cin >> S1 >> V1 >> S2 >> V2;

    if (V1 == V2) {
        cout << -1 << endl;
    } else {
        if ((S2 - S1) * (V1 - V2) > 0) {
            cout << (S2 - S1) / (V1 - V2) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
