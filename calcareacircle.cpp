#include<bits/stdc++.h>
int main() {
    // Input radius
    double radius;
    std::cin >> radius;
    double M_PI = 3.14;
    // Calculate circumference
    double circumference = 2 * M_PI * radius;

    // Calculate area
    double area = M_PI * radius * radius;

    // Output results rounded to one decimal place
    std::cout << std::fixed << std::setprecision(1);
    std::cout << circumference << std::endl;
    std::cout << area << std::endl;

    return 0;
}
