#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int a[(int) 1e5 + 5];

bool check(double mid, int a[], int n, int l) {
    double left = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] - mid > left) {
            return false;
        }
        left = a[i] + mid;
    }
    return left >= l;
}

int main() {
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    double low = 0, high = l, mid;
    int tmp = 500;
    while(tmp--) {
        mid = low + (high - low) / 2;
        if(check(mid, a, n, l)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(6) << high << endl;
    return 0;
}
