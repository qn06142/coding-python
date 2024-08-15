#include <iostream>
#include <vector>
using namespace std;

struct Meeting {
    int start, end, profit;
};

// Function to check if a subset is valid (no overlapping meetings)
bool isValid(const vector<Meeting>& subset) {
    for (int i = 0; i < subset.size(); ++i) {
        for (int j = i + 1; j < subset.size(); ++j) {
            if (!(subset[i].end <= subset[j].start || subset[j].end <= subset[i].start)) {
                return false;  // Overlapping found
            }
        }
    }
    return true;  // No overlapping found
}

// Function to calculate the total profit of a subset
int calculateProfit(const vector<Meeting>& subset) {
    int totalProfit = 0;
    for (const auto& meeting : subset) {
        totalProfit += meeting.profit;
    }
    return totalProfit;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end >> meetings[i].profit;
    }

    int maxProfit = 0;

    // Generate all subsets using bit masking
    for (int mask = 0; mask < (1 << N); ++mask) {
        vector<Meeting> subset;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(meetings[i]);
            }
        }
        if (isValid(subset)) {
            int profit = calculateProfit(subset);
            maxProfit = max(maxProfit, profit);
        }
    }

    cout << maxProfit << endl;

    return 0;
}
