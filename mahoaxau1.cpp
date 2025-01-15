#include <iostream>
#include <string>
using namespace std;

int main() {

    string S, A, B;
    long long K;

    // Read input
    cin >> S >> K >> A >> B;

    // Perform K iterations of transformation
    for (long long i = 0; i < K; ++i) {
        string new_S = S;
        for (int j = 0; j < (int)S.size(); ++j) {
            // Find the mapped character
            char current = S[j];
            int index = A.find(current);
            new_S[j] = B[index];
        }
        S = new_S; // Update the string for the next iteration
    }

    // Output the final result
    cout << S << endl;

    return 0;
}
