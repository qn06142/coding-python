#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Create a vector of vectors to store the positions of each author's books
    vector<vector<int>> positions(M + 1);
    for (int i = 0; i < N; ++i) {
        positions[A[i]].push_back(i);
    }

    int books_to_remove = 0;

    // For each author, find how many disjoint segments we have
    for (int author = 1; author <= M; ++author) {
        if (positions[author].empty()) continue;

        // Calculate how many segments we have for this author
        int segments = 1; // at least one segment exists
        for (int i = 1; i < positions[author].size(); ++i) {
            if (positions[author][i] != positions[author][i - 1] + 1) {
                segments++;
            }
        }

        // Add the number of books that need to be moved for this author
        // This is equivalent to removing all other segments except one
        books_to_remove += (positions[author].size() - segments);
    }

    cout << books_to_remove << endl;

    return 0;
}
