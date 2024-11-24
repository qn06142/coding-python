#include<iostream>
#include<cmath>
using namespace std;
int divs[(int) 1e6];
int main() {
    int q;
    cin >> q;
    for(int i = 1; i <= 1e5; i++) {
        for(int j = i; j <= 1e5; j += i) {
            divs[j] ++;
        }
    }
    while(q--) {
        int n;
        cin >> n;
        cout << ((divs[n] % 2 == 1) ? 1 : 0) << endl;
    }
}