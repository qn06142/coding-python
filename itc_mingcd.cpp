#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
long long seqMin[4 * maxn], seqGcd[4 * maxn], a[maxn];
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void buildMin(int node = 1, int l = 1, int r = n) {
    if (l == r) {
        seqMin[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        buildMin(node * 2, l, mid);
        buildMin(node * 2 + 1, mid + 1, r);
        seqMin[node] = min(seqMin[node * 2], seqMin[node * 2 + 1]);
    }
}

void buildGcd(int node = 1, int l = 1, int r = n) {
    if (l == r) {
        seqGcd[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        buildGcd(node * 2, l, mid);
        buildGcd(node * 2 + 1, mid + 1, r);
        seqGcd[node] = gcd(seqGcd[node * 2], seqGcd[node * 2 + 1]);
    }
}

long long getMin(int x, int y, int node = 1, int l = 1, int r = n) {
    if (x > r or y < l) {
        return LLONG_MAX;
    } else {
        if (x <= l and y >= r) {
            return seqMin[node];
        }
        int mid = (l + r) / 2;
        long long L = getMin(x, y, node * 2, l, mid);
        long long R = getMin(x, y, node * 2 + 1, mid + 1, r);
        return min(L, R);
    }
}

long long getGcd(int x, int y, int node = 1, int l = 1, int r = n) {
    if (x > r or y < l) {
        return 0;
    } else {
        if (x <= l and y >= r) {
            return seqGcd[node];
        }
        int mid = (l + r) / 2;
        long long L = getGcd(x, y, node * 2, l, mid);
        long long R = getGcd(x, y, node * 2 + 1, mid + 1, r);
        return gcd(L, R);
    }
}

int findMaxLengthHarmoniousSubarray() {
    int max_length = 0;
    for (int l = 1; l <= n; ++l) {
        int low = l, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            int gcd_val = getGcd(l, mid);
            int min_val = getMin(l, mid);
            if (gcd_val == min_val) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        max_length = max(max_length, low - l);
    }
    return max_length;
}

int main() {
    ifstream fin("MINGCD.INP");
    ofstream fout("MINGCD.OUT");

    fin >> n;
    int k;  // The variable 'k' is not used in this implementation, but we still need to read it
    fin >> k;

    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }

    // Build segment trees for GCD and Min
    buildMin();
    buildGcd();

    int max_length = findMaxLengthHarmoniousSubarray();

    fout << max_length << endl;

    fin.close();
    fout.close();

    return 0;
}
