#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end, profit;
};

bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

int findLastNonConflicting(vector<Meeting>& meetings, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (meetings[j].end <= meetings[i].start)
            return j;
    }
    return -1;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end >> meetings[i].profit;
    }

    sort(meetings.begin(), meetings.end(), compare);

    vector<int> dp(N, 0);
    dp[0] = meetings[0].profit;

    for (int i = 1; i < N; ++i) {
        int includeProfit = meetings[i].profit;
        int l = findLastNonConflicting(meetings, i);
        if (l != -1) {
            includeProfit += dp[l];
        }

        dp[i] = max(includeProfit, dp[i - 1]);
    }

    cout << dp[N - 1] << endl;

    return 0;
}
