#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,O3,fast-math")
#pragma GCC target("popcnt,avx,avx2")

using v8si = int __attribute__((vector_size(32))); // Define a type for 8x32-bit integers

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    v8si c_vec = {c, c, c, c, c, c, c, c}; // Broadcast c to a vector
    v8si a_vec = {a, a, a, a, a, a, a, a}; // Broadcast a to a vector
    v8si b_vec = {b, b, b, b, b, b, b, b}; // Broadcast b to a vector

    v8si indices = {1, 2, 3, 4, 5, 6, 7, 8}; // Starting indices
    v8si increment = {8, 8, 8, 8, 8, 8, 8, 8}; // Increment vector

    v8si valid_counts = {0, 0, 0, 0, 0, 0, 0, 0}; // Vector to accumulate valid counts

    for (long long iter = 1; iter <= c; iter += 8) {
        // Compute c - a * x for the vector of indices
        v8si curr = c_vec - (a_vec * indices);

        // Compute curr % b
        v8si mod = curr % b_vec;

        // Check divisibility by b (mod == 0)
        v8si is_divisible = (mod == (v8si){0, 0, 0, 0, 0, 0, 0, 0});

        // Compute y = (c - a * x) / b where divisible
        v8si y = curr / b_vec;

        // Check if y > 0
        v8si is_positive = (y > (v8si){0, 0, 0, 0, 0, 0, 0, 0});

        // Combine masks for valid solutions
        v8si valid_mask = is_divisible & is_positive;

        // Increment valid_counts vector
        valid_counts += valid_mask;

        // Increment indices
        indices += increment;
    }

    // Sum all elements of valid_counts
    int valid_array[8];
    __builtin_memcpy(valid_array, &valid_counts, sizeof(valid_counts));
    long long total_count = 0;
    for (int i = 0; i < 8; i++) {
        total_count += valid_array[i];
    }

    cout << total_count << '\n';
    return 0;
}
