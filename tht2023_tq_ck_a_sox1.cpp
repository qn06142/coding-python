#include <iostream>
using namespace std;

char findPlayerWithTurns(long long N, long long X) {
    long long left = 1, right = N; // Dãy [1, N]
    int turn = 1; // Bắt đầu từ lượt 1 (A)

    while (left <= right) {
        // Debug: Print the current turn and range
        cout << left  << ", ";

        if (turn % 3 == 1) { // A's turn
            if (turn % 2 == 1) { // A lấy số bé nhất
                if (left == X) return 'A';
                ++left;
            } else { // A lấy số lớn nhất
                if (right == X) return 'A';
                --right;
            }
        } else if (turn % 3 == 2) { // B's turn
            if (left == X) return 'B';
            ++left;
        } else { // C's turn
            if (turn % 2 == 1) { // C lấy số lớn nhất
                if (right == X) return 'C';
                --right;
            } else { // C lấy số bé nhất
                if (left == X) return 'C';
                ++left;
            }
        }
        ++turn;
    }
    return '?'; // Trường hợp không xảy ra
}

int main() {
    long long N, X;
    cin >> N >> X;
    char result = findPlayerWithTurns(N, X);
    cout << "The player who takes number " << X << " is: " << result << endl;
    return 0;
}
