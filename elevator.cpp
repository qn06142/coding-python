#include <algorithm>
#include <vector>
#include <iostream>

int min_elevator_trips(std::vector<int>& weights, int max_weight) {
    std::sort(weights.begin(), weights.end(), std::greater<int>());
    int trips = 0;
    int i = 0;
    int j = weights.size() - 1;
    while (i <= j) {
        if (weights[i] + weights[j] <= max_weight) {
            j--;
        }
        trips++;
        i++;
    }
    return trips;
}

int main() {
    std::vector<int> weights = {60, 80, 40, 60, 50};
    int max_weight = 200;
    std::cout << min_elevator_trips(weights, max_weight) << std::endl;
    return 0;
}
