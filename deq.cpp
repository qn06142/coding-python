#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void find_B(const vector<int>& A) {
    int n = A.size();
    vector<int> B(n, 0); // Initialize B with zeros
    stack<int> st; // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() > A[i]) st.pop();
        if (st.empty()) cout<<0<<" "; else cout<<st.top()<<" ";
        st.push(A[i]);

    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    find_B(A);

    return 0;
}
