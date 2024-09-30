#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> paint[n + 1];  
    int frame[m + 1];             

    for (int i = 1; i <= n; i++) {  
        cin >> paint[i].second >> paint[i].first;
    }

    for (int i = 1; i <= m; i++) {  
        cin >> frame[i];
    }

    sort(paint + 1, paint + n + 1);  
    sort(frame + 1, frame + m + 1);  

    int paint_i = n;
    int answer = 0;

    for (int i = m; i >= 1; i--) {  
        int size = frame[i];

        while (paint_i >= 1 && paint[paint_i].second > size) {  
            paint_i--;
        }

        if (paint_i < 1) {
            cout << answer << '\n';
            return 0;
        }

        paint_i--;
        answer++;
    }

    cout << answer << '\n';
    return 0;
}