#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

#define int long long
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int result = 0; 

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = a[i] + a[left] + a[right];
            if (sum <= m) {
                result = max(result, sum); 
                left++; 
            } else {
                right--; 
            }
        }
    }

    cout << result << endl;
    return 0;
}