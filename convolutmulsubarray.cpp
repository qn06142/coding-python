#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 5005;
int a[MAXN], b[MAXN];
int max_convolution(int n) {
    int max_convolution_sum = INT_MIN;

    for (int k = 1; k <= n; ++k) {

        int current_convolution_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_convolution_sum += a[i] * b[i];
        }
        max_convolution_sum = max(max_convolution_sum, current_convolution_sum);

        for (int i = k; i < n; ++i) {
            current_convolution_sum += a[i] * b[i] - a[i - k] * b[i - k];
            max_convolution_sum = max(max_convolution_sum, current_convolution_sum);
        }
    }

    return max_convolution_sum;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int result = max_convolution(n);
    cout << result << endl;

    return 0;
}