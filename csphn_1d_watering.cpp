#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];

    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int count = 0; 

    for(int i = 1; i < n; ++i) {

        if(h[i] < h[i-1] and h[i] > h[i + 1]) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}