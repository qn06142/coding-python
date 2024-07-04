#include <cstdio>      // For standard input/output functions
#include <vector>      // For using the vector container
#include <algorithm>   // For sorting and upper_bound functions

using namespace std;

const int MAXN = 20;   // Maximum value for N
int n;                 // Number of levels in the tournament
int a[1 << MAXN];      // Array to store the 2^N integers

// Function to calculate the highest level a number can reach
int calc(int x) {
    if (x == 0) return 0;  // If x is 0, return 0
    for (int i = n - 1; i >= 0; --i) {  // Iterate from n-1 to 0
        if ((1 << i) < x) x -= (1 << i);  // If 2^i is less than x, subtract 2^i from x
        else return n - i;  // Otherwise, return n - i
    }
    return n;  // Return n if no other condition is met
}

int main(void) {
    scanf("%d", &n);  // Read the value of n
    vector<int> V;    // Vector to store the sequence of 2^N integers
    for (int i = 0; i < (1 << n); ++i) {  // Loop to read the integers
        scanf("%d", &a[i]);  // Read each integer into array a
        V.push_back(a[i]);   // Add each integer to vector V
    }
    sort(V.begin(), V.end());  // Sort the vector V in ascending order
    for (int i = 0; i < (1 << n); ++i) {  // Loop through each number in array a
        // Find the position of a[i] in the sorted vector V
        int pos = V.end() - upper_bound(V.begin(), V.end(), a[i]);
        // Print the highest level the number can reach
        printf("%d ", calc(pos));
    }
    return 0;  // Return 0 to indicate successful execution
}
