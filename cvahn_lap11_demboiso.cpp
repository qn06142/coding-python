#include <fstream>
#include <algorithm>

int main() {
    int k, m, n;
    std::ifstream input("demboi.inp");
    input >> k >> m >> n;
    input.close();

    int count = 0;
    for (int i = std::min(k, m); i <= n; ++i) {
        if (i % k == 0 || i % m == 0) {
            ++count;
        }
    }

    std::ofstream output("demboi.out");
    output << count;
    output.close();

    return 0;
}

