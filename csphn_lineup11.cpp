#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;


bool isValidSegment(const vector<int>& a, int start, int end) {
    int maxHeight = a[start];
    for (int i = start + 1; i <= end; i++) {
        if (a[i] > maxHeight) return false;
    }
    return true;
}


int countPartitions(const vector<int>& a, int n, int index) {
    if (index > n) return 1; 
    int count = 0;
    for (int i = index; i <= n; i++) {
        if (isValidSegment(a, index, i)) {
            count = (count + countPartitions(a, n, i + 1)) % MOD;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int result = countPartitions(a, n, 1);
    cout << result << endl;

    return 0;
}
