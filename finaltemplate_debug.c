#include <stdio.h>    
#include <stdbool.h>  
#include <string.h>   
#include <stddef.h>   
#include <stdbool.h>
#define true 1
#define false 0
#ifndef ONLINE_JUDGE

static void __debug_print_char(char x) { fprintf(stderr, "'%c'", x); }
static void __debug_print_bool(bool x) { fprintf(stderr, x ? "T" : "F"); }
static void __debug_print_signed_short(signed short int x) { fprintf(stderr, "%hd", x); }
static void __debug_print_unsigned_short(unsigned short int x) { fprintf(stderr, "%hu", x); }
static void __debug_print_signed_int(signed int x) { fprintf(stderr, "%d", x); }
static void __debug_print_unsigned_int(unsigned int x) { fprintf(stderr, "%u", x); }
static void __debug_print_signed_long(signed long int x) { fprintf(stderr, "%ld", x); }
static void __debug_print_unsigned_long(unsigned long int x) { fprintf(stderr, "%lu", x); }
static void __debug_print_signed_long_long(signed long long int x) { fprintf(stderr, "%lld", x); }
static void __debug_print_unsigned_long_long(unsigned long long int x) { fprintf(stderr, "%llu", x); }
static void __debug_print_float(float x) { fprintf(stderr, "%f", x); }
static void __debug_print_double(double x) { fprintf(stderr, "%lf", x); }
static void __debug_print_long_double(long double x) { fprintf(stderr, "%Lf", x); }
static void __debug_print_string(const char* x) { fprintf(stderr, "\"%s\"", x ? x : "(null)"); }
static void __debug_print_pointer(const void* x) { fprintf(stderr, "%p", x); }

#define __print_generic(X) _Generic((X), \
    _Bool: __debug_print_bool, \
    char: __debug_print_char, \
    signed char: __debug_print_char, \
    unsigned char: __debug_print_char, \
    signed short int: __debug_print_signed_short, \
    unsigned short int: __debug_print_unsigned_short, \
    signed int: __debug_print_signed_int, \
    unsigned int: __debug_print_unsigned_int, \
    signed long int: __debug_print_signed_long, \
    unsigned long int: __debug_print_unsigned_long, \
    signed long long int: __debug_print_signed_long_long, \
    unsigned long long int: __debug_print_unsigned_long_long, \
    float: __debug_print_float, \
    double: __debug_print_double, \
    long double: __debug_print_long_double, \
    char*: __debug_print_string, \
    const char*: __debug_print_string, \
    void*: __debug_print_pointer, \
    default: __debug_print_pointer \
)(X)

#define debug(VAR) \
    do { \
        fprintf(stderr, "%s:%d: [%s = ", __FILE__, __LINE__, #VAR); \
        __print_generic(VAR); \
        fprintf(stderr, "]\n"); \
    } while (0)

#define debugArr(ARR, N) \
    do { \
        fprintf(stderr, "%s:%d: [%s = {", __FILE__, __LINE__, #ARR); \
        for (size_t __i = 0; __i < (N); ++__i) { \
            if (__i > 0) { \
                fprintf(stderr, ","); \
            } \
             \
             \
             \
            __print_generic((ARR)[__i]); \
        } \
        fprintf(stderr, "}]\n"); \
    } while (0)

#define __DEBUG_ARG1(N, V, ...) V
#define __DEBUG_REST(N, V, ...) __VA_ARGS__
#define __DEBUG_SEP() fprintf(stderr, " || ") 

#define __DEBUG_PRINT_ONE(NAMES_STR_PTR, FIRST_VAR, ...) \
    do { \
        const char* __current_name = *(NAMES_STR_PTR); \
        int __len = 0; \
        int __brackets = 0; \
        while (__current_name[__len] != '\0' && (__current_name[__len] != ',' || __brackets != 0)) { \
            if (__current_name[__len] == '(' || __current_name[__len] == '{' || __current_name[__len] == '[') __brackets++; \
            else if (__current_name[__len] == ')' || __current_name[__len] == '}' || __current_name[__len] == ']') __brackets--; \
            __len++; \
        } \
        fprintf(stderr, "%.*s = ", __len, __current_name); \
        __print_generic(FIRST_VAR); \
        *(NAMES_STR_PTR) = __current_name + __len; \
        if (**(NAMES_STR_PTR) == ',') { \
            *(NAMES_STR_PTR) += 1;  \
            while (**(NAMES_STR_PTR) == ' ') *(NAMES_STR_PTR) += 1;  \
        } \
    } while(0)

#define __DEBUG_PROCESS_ARGS_1(NAMES_STR_PTR, VAR1) \
    __DEBUG_PRINT_ONE(NAMES_STR_PTR, VAR1)

#define __DEBUG_PROCESS_ARGS_N(NAMES_STR_PTR, VAR1, ...) \
    __DEBUG_PRINT_ONE(NAMES_STR_PTR, VAR1); \
    __DEBUG_SEP(); \
    __DEBUG_INVOKE_PROCESS(__DEBUG_COUNT_ARGS(__VA_ARGS__), NAMES_STR_PTR, __VA_ARGS__)

#define __DEBUG_COUNT_ARGS(...) __DEBUG_ARGS_N(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define __DEBUG_ARGS_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

#define __DEBUG_INVOKE_PROCESS(N, NAMES_STR_PTR, ...) __DEBUG_INVOKE_PROCESS_##N(NAMES_STR_PTR, __VA_ARGS__)
#define __DEBUG_INVOKE_PROCESS_1(NAMES_STR_PTR, ...) __DEBUG_PROCESS_ARGS_1(NAMES_STR_PTR, __VA_ARGS__)
#define __DEBUG_INVOKE_PROCESS_2(NAMES_STR_PTR, ...) __DEBUG_PROCESS_ARGS_N(NAMES_STR_PTR, __VA_ARGS__)
#define __DEBUG_INVOKE_PROCESS_3(NAMES_STR_PTR, ...) __DEBUG_PROCESS_ARGS_N(NAMES_STR_PTR, __VA_ARGS__)
#define __DEBUG_INVOKE_PROCESS_4(NAMES_STR_PTR, ...) __DEBUG_PROCESS_ARGS_N(NAMES_STR_PTR, __VA_ARGS__)
#define __DEBUG_INVOKE_PROCESS_5(NAMES_STR_PTR, ...) __DEBUG_PROCESS_ARGS_N(NAMES_STR_PTR, __VA_ARGS__)

#define debugMulti(...) \
    do { \
        fprintf(stderr, "%s:%d: [", __FILE__, __LINE__); \
        const char* __debug_names_str = #__VA_ARGS__; \
        const char** __debug_names_ptr = &__debug_names_str; \
        __DEBUG_INVOKE_PROCESS(__DEBUG_COUNT_ARGS(__VA_ARGS__), __debug_names_ptr, __VA_ARGS__); \
        fprintf(stderr, "]\n"); \
    } while (0)

#else 

#define debug(...) \
    do {           \
    } while (0)
#define debugArr(...) \
    do {              \
    } while (0)
#define debugMulti(...) \
    do {                \
    } while (0)

#endif 

int main() {
    int i = 10;
    double pi = 3.14159;
    char c = 'X';
    const char* msg = "Hello C!";
    bool flag = true;
    int numbers[] = {10, 20, 30, 40, 50};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);
    float f = 1.23f;
    long long big_num = 1234567890123LL;
    int *ptr = &i;
    int *null_ptr = NULL;

    debug(i);        
    debug(pi);       
    debug(c);        
    debug(msg);      
    debug(flag);     
    debug(f);        
    debug(big_num);  
    debug(ptr);      
    debug(null_ptr); 

    debugArr(numbers, count); 

    debugMulti(i, pi, msg, flag);
    debugMulti(numbers[1], count); 

    return 0;
}