#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countPairs(const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> countA, countB;
    
    // Count occurrences in array a
    for (int num : a) {
        countA[num]++;
    }
    
    // Count occurrences in array b
    for (int num : b) {
        countB[num]++;
    }
    
    // Calculate the number of pairs
    int result = 0;
    for (const auto& pair : countA) {
        int num = pair.first;
        if (countB.find(num) != countB.end()) {
            result += pair.second * countB[num];
        }
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    cout << countPairs(a, b) << endl;
    return 0;
}
