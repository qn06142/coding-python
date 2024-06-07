#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sàng Eratosthenes để tìm tất cả các số nguyên tố tới max_num
vector<bool> sieve_of_eratosthenes(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= max_num; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= max_num; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

// Đếm số tam giác với các cạnh cùng màu
int count_triangles(int n, const vector<bool>& is_prime) {
    vector<vector<int>> adjacency_matrix(n + 1, vector<int>(n + 1, 0));
    
    // Xây dựng ma trận kề
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (is_prime[i + j]) {
                adjacency_matrix[i][j] = adjacency_matrix[j][i] = 1; // Màu xanh
            } else {
                adjacency_matrix[i][j] = adjacency_matrix[j][i] = 2; // Màu vàng
            }
        }
    }

    int green_triangles = 0;
    int yellow_triangles = 0;

    // Đếm tam giác
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (adjacency_matrix[i][j] == adjacency_matrix[i][k] &&
                    adjacency_matrix[i][j] == adjacency_matrix[j][k]) {
                    if (adjacency_matrix[i][j] == 1) {
                        ++green_triangles;
                    } else if (adjacency_matrix[i][j] == 2) {
                        ++yellow_triangles;
                    }
                }
            }
        }
    }

    return green_triangles + yellow_triangles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> results(T);
    vector<int> ns(T);

    for (int i = 0; i < T; ++i) {
        cin >> ns[i];
    }

    int max_n = *max_element(ns.begin(), ns.end());
    auto is_prime = sieve_of_eratosthenes(2 * max_n);

    for (int i = 0; i < T; ++i) {
        results[i] = count_triangles(ns[i], is_prime);
    }

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}