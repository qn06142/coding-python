#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int BASE = 31;

void compute_hashes(const string &t, vector<long long> &hash1, vector<long long> &hash2, vector<long long> &power1, vector<long long> &power2) {
    int n = t.size();
    hash1[0] = hash2[0] = 0;
    power1[0] = power2[0] = 1;

    for (int i = 1; i <= n; i++) {
        hash1[i] = (hash1[i - 1] * BASE + (t[i - 1] - 'a' + 1)) % MOD1;
        hash2[i] = (hash2[i - 1] * BASE + (t[i - 1] - 'a' + 1)) % MOD2;
        power1[i] = (power1[i - 1] * BASE) % MOD1;
        power2[i] = (power2[i - 1] * BASE) % MOD2;
    }
}

pair<long long, long long> get_hash(int l, int r, const vector<long long> &hash1, const vector<long long> &hash2, const vector<long long> &power1, const vector<long long> &power2) {
    long long hash_val1 = (hash1[r + 1] - hash1[l] * power1[r - l + 1] % MOD1 + MOD1) % MOD1;
    long long hash_val2 = (hash2[r + 1] - hash2[l] * power2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {hash_val1, hash_val2};
}

int main() {
    string s, t;
    cin >> s >> t;

    int count_0 = 0, count_1 = 0;
    for (char c : s) {
        if (c == '0') count_0++;
        else count_1++;
    }

    int n = t.length();  
    int m = s.length();  
    int result = 0;

    vector<long long> hash1(n + 1), hash2(n + 1), power1(n + 1), power2(n + 1);
    compute_hashes(t, hash1, hash2, power1, power2);

    for (int len_r0 = 1; len_r0 <= n / count_0; len_r0++) {
        if ((n - count_0 * len_r0) % count_1 != 0) continue;
        int len_r1 = (n - count_0 * len_r0) / count_1;
        if (len_r1 <= 0) continue;

        pair<long long, long long> hash_r0 = {-1, -1}, hash_r1 = {-1, -1};
        bool valid = true;
        int idx = 0;

        for (char c : s) {
            if (c == '0') {
                pair<long long, long long> current_hash = get_hash(idx, idx + len_r0 - 1, hash1, hash2, power1, power2);
                if (hash_r0.first == -1) hash_r0 = current_hash;
                else if (hash_r0 != current_hash) {
                    valid = false;
                    break;
                }
                idx += len_r0;
            } else {
                pair<long long, long long> current_hash = get_hash(idx, idx + len_r1 - 1, hash1, hash2, power1, power2);
                if (hash_r1.first == -1) hash_r1 = current_hash;
                else if (hash_r1 != current_hash) {
                    valid = false;
                    break;
                }
                idx += len_r1;
            }
        }

        if (valid && hash_r0 != hash_r1) result++;
    }

    cout << result << endl;
    return 0;
}