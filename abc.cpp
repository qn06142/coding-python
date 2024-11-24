#include<iostream>
#include<cmath>
using namespace std;

int main() {
    long long s, x, y, l;
    cin >> s >> x >> y >> l;
    long long da = l;
    long long db = abs(s - l);
    double ta = da / x, tb = db / y;
    if(ta > tb) {
        cout << "A";
    } else if(ta < tb) {
        cout << "B";
    } else {
        cout << "C";
    }
}