#include <iostream>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;
unordered_map<int, long long> empty_;
unordered_map<int, long long> conv(long long n) {
    unordered_map<int, long long> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
    return factors;
}

unordered_map<int, long long> lcm(const unordered_map<int, long long>& a, const unordered_map<int, long long>& b) {
    unordered_map<int, long long> result = a;
    for (auto& p : b) {
        result[p.first] = max(result[p.first], p.second);
    }
    return result;
}

unordered_map<int, long long> mul(const unordered_map<int, long long>& a, const unordered_map<int, long long>& b) {
    unordered_map<int, long long> result = a;
    for (auto& p : b) {
        result[p.first] += p.second;
    }
    return result;
}

unordered_map<int, long long> div(const unordered_map<int, long long>& a, const unordered_map<int, long long>& b) {
    unordered_map<int, long long> result = a;
    for (auto& p : b) {
        result[p.first] -= p.second;
    }
    return result;
}

long long stor[(int)1e6];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    stack<unordered_map<int, long long>> stacc;
    stacc.push(empty_);  // Push identity factorization for 1
    stacc.push(empty_);

    for (int i = 1; i <= n; i++) {
        cin >> stor[i];
    }

    for (int i = 3 * n + 1; i >= 1; i--) {
        if (stor[i] == -1) {
            stacc.push({});  // Push empty_ factorization
        } else {
            if (stor[i + 1] == -1) continue;

            auto x = stacc.top();
            stacc.pop();
            auto y = stacc.top();
            stacc.pop();

            auto a = conv(stor[i]);
            auto b = conv(stor[i + 1]);

            stacc.push(div(mul(lcm(mul(x, a), mul(y, b)), conv(stor[i] + stor[i + 1])), mul(conv(stor[i]), conv(stor[i + 1]))));

            if (stor[i - 1] != -1) i--;
        }
    }

    auto top = stacc.top();
    long long ans = 1;
    for (auto& p : top) {
        for (int j = 0; j < p.second; j++) {
            ans *= p.first;
        }
    }

    cout << ans << endl;
}
