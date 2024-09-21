#include <cstdio>

int main() {
    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    long long A[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }

    long long current_sum = 0;
    long long count = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        current_sum += A[end];

        while (current_sum >= k) {

            count += (n - end);

            current_sum -= A[start];
            start++;
        }
    }

    printf("%lld\n", count);

    return 0;
}