#include<bits/stdc++.h>
using namespace std;
using namespace std;

typedef unsigned long long ull;

// Function to generate all numbers with a given length without leading zeroes
vector<int> generateNumbers(int len) {
    vector<int> numbers;
    int start = pow(10, len - 1);
    int end = pow(10, len) - 1;
    for (int i = start; i <= end; ++i) {
        numbers.push_back(i);
    }
    return numbers;
}

// Function to count number of valid expressions <= given expression
ull countExpressions(int A, int B, int C, int maxA, int maxB) {
    ull count = 0;
    vector<int> cNumbers = generateNumbers(C);
    for (int a = pow(10, A - 1); a <= maxA; ++a) {
        for (int b = pow(10, B - 1); b <= maxB; ++b) {
            int c = a + b;
            if (to_string(c).length() == C && c <= cNumbers.back()) {
                ++count;
            }
        }
    }
    return count;
}

string findExpression(int A, int B, int C, ull k) {
    int a_start = pow(10, A - 1);
    int a_end = pow(10, A) - 1;
    int b_start = pow(10, B - 1);
    int b_end = pow(10, B) - 1;
    
    ull left = 0, right = 1e18;
    string result = "-1";
    
    while (left <= right) {
        ull mid = left + (right - left) / 2;
        ull count = countExpressions(A, B, C, mid / (b_end + 1), mid % (b_end + 1));
        
        if (count >= k) {
            result = to_string(mid / (b_end + 1)) + "+" + to_string(mid % (b_end + 1)) + "=" + to_string(mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        ull k;
        cin >> A >> B >> C >> k;
        
        string result = findExpression(A, B, C, k);
        cout << result << endl;
    }
    return 0;
}