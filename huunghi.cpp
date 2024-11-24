#include <iostream>

int TU(int a) {
    int Tg = 0;
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            Tg += i;
        }
    }
    return Tg;
}

int main() {
    int n;
    std::cout << "Nhap so n: ";
    std::cin >> n;
    for (int a = 1; a <= n; a++) {
        int b = TU(a);
        if (TU(b) == a) {
            std::cout << a << " " << b << std::endl;
        }
    }
    return 0;
}


