def bad_fib(n):
    if n <= 1:
        return n
    return bad_fib(n-1) + bad_fib(n-2)
