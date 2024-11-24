#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    #define int long long
    int N;
    cin >> N;
    int t[N];
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    sort(t, t + N);

    int time = 0;  
    int i = N - 1;  

    while (i >= 3) {

        int option1 = 2 * t[1] + t[0] + t[i];

        int option2 = 2 * t[0] + t[i] + t[i - 1];

        time += min(option1, option2);
        i -= 2;
    }

    if (i == 2) {
        time += t[2] + t[0] + t[1];
    } else if (i == 1) {
        time += t[1];
    } else if (i == 0) {
        time += t[0];
    }

    cout << time << endl;
    return 0;
}