#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d;
    int r;
} Book;

int cmp(const void *a, const void *b) {
    Book *bookA = (Book *)a;
    Book *bookB = (Book *)b;
    if (bookA->d != bookB->d)
        return bookA->d - bookB->d;
    else
        return bookB->r - bookA->r; 
}

int main(){
    int n;
    if(scanf("%d", &n) != 1) return 1;

    Book *books = (Book *)malloc(n * sizeof(Book));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &books[i].d, &books[i].r);
    }

    qsort(books, n, sizeof(Book), cmp);

    int *dp = (int *)malloc(n * sizeof(int));
    int len = 0;

    for (int i = 0; i < n; i++) {
        int r = books[i].r;

        int lo = 0, hi = len;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (dp[mid] < r)
                lo = mid + 1;
            else
                hi = mid;
        }
        dp[lo] = r;
        if (lo == len)
            len++;
    }

    printf("%d\n", len);

    free(books);
    free(dp);
    return 0;
}