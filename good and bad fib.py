def bad_fib(n):
    if n <= 1:
        return n
    return bad_fib(n-1) + bad_fib(n-2)
def good_fib(n):
    inp = n
    fib = [1,1]
    def oneinterfib(val1, val2):
        return val1 + val2
    for i in range(2, inp):
        fib.append(oneinterfib(fib[i-1], fib[i-2]))
    return fib
