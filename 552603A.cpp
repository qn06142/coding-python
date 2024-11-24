#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);  // Input number of test cases
    
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);  // Input the sides a and b
        
        // Calculate the area of the right triangle
        double area = 0.5 * a * b;
        
        // Print the result with a precision that meets the problem's requirement
        printf("%.6f\n", area);
    }
    
    return 0;
}
