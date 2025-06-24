#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define DEBUG_UTIL_C23_H
#ifdef DEBUG_UTIL_C23_H
#define DEBUG_UTIL_C23_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>
#include <stdarg.h>

#ifndef ONLINE_JUDGE

static void __d_pb(bool x){fprintf(stderr,"%s",x?"T":"F");}
static void __d_pc(char x){fprintf(stderr,"'%c'",x);}
static void __d_psch(signed char x){fprintf(stderr,"%hhd",x);}
static void __d_puch(unsigned char x){fprintf(stderr,"%hhu",x);}
static void __d_pssh(signed short x){fprintf(stderr,"%hd",x);}
static void __d_push(unsigned short x){fprintf(stderr,"%hu",x);}
static void __d_psi(signed int x){fprintf(stderr,"%d",x);}
static void __d_pui(unsigned int x){fprintf(stderr,"%u",x);}
static void __d_psl(signed long x){fprintf(stderr,"%ld",x);}
static void __d_pul(unsigned long x){fprintf(stderr,"%lu",x);}
static void __d_psll(signed long long x){fprintf(stderr,"%lld",x);}
static void __d_pull(unsigned long long x){fprintf(stderr,"%llu",x);}
static void __d_pf(float x){fprintf(stderr,"%g",x);}
static void __d_pd(double x){fprintf(stderr,"%g",x);}
static void __d_pld(long double x){fprintf(stderr,"%Lg",x);}
static void __d_ps(const char* x){if(!x)fprintf(stderr,"\"(null)\"");else fprintf(stderr,"\"%s\"",x);}
static void __d_pp(const void* x){if(!x)fprintf(stderr,"NULL");else fprintf(stderr,"%p",x);}

#define __dp(X) _Generic((X), \
    bool: __d_pb, _Bool: __d_pb, \
    char: __d_pc, signed char: __d_psch, unsigned char: __d_puch, \
    signed short: __d_pssh, unsigned short: __d_push, \
    signed int: __d_psi, unsigned int: __d_pui, \
    signed long: __d_psl, unsigned long: __d_pul, \
    signed long long: __d_psll, unsigned long long: __d_pull, \
    float: __d_pf, double: __d_pd, long double: __d_pld, \
    char*: __d_ps, const char*: __d_ps, \
    default: __d_pp \
)(X)

static void __dph(const char* n, va_list a){
    (void)a;const char*p=n;bool f=1;
    while(*p){while(*p==' ')p++;if(!*p)break;const char*s=p;size_t b=0;
    while(*p!='\0'&&(*p!=','||b!=0)){if(*p=='('||*p=='{'||*p=='[')b++;else if(*p==')'||*p=='}'||*p==']')b--;p++;}
    if(!f)fprintf(stderr," || ");fprintf(stderr,"%.*s = ?",(int)(p-s),s);f=0;if(*p==',')p++;}}

static void __dpe(int l, const char* n, ...){
    fprintf(stderr,"%d: [",l);va_list a;va_start(a,n);__dph(n,a);va_end(a);fprintf(stderr,"]\n");}

#define debug(...) __dpe(__LINE__, #__VA_ARGS__, __VA_ARGS__)

#define debugArr(arr, size) \
    do { \
        size_t sz = (size_t)(size); \
        fprintf(stderr, "%d: [%s (%zu element%s) = {", __LINE__, #arr, sz, (sz==1?"":"s")); \
        for (size_t i = 0; i < sz; ++i) { \
            if (i > 0) fprintf(stderr, ", "); \
            __dp((arr)[i]); \
        } \
        fprintf(stderr, "}]\n"); \
    } while (0)

#else

#define debug(...) do{}while(0)
#define debugArr(...) do{}while(0)
#define __dp(X) do{}while(0)

#endif

#endif // DEBUG_UTIL_C23_H
#pragma GCC optimize("trapv")
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long solve(int a[], int n, int b[], int m) {

    if (m < n) {
        return -1;
    }

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
    long long dp[n+1][m+1];
    debug("%d", n);

    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {

            if (dp[i][j-1] < dp[i][j]) {
                dp[i][j] = dp[i][j-1];
            }

            if (dp[i-1][j-1] != LLONG_MAX) {
                long long cost = abs(a[i-1] - b[j-1]);
                if (dp[i-1][j-1] + cost < dp[i][j]) {
                    dp[i][j] = dp[i-1][j-1] + cost;
                }
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    int b[m];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i - 1]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &b[i - 1]);
    }

    if (m < n) {
        return 1;
    }

    long long result = solve(a, n, b, m);
    if(result != -1)
        printf("%lld", result);

    return 0;
}