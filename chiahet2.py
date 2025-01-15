def binpow(a, b):
    res = 1
    while b > 0:
        if b & 1:
            res *= a
        a *= a
        b >>= 1
    return res

def F(n, x):
    return n // (1 << x)

def main():

    import sys
    sys.stdin = open("CHIAHET2.INP", "r")
    sys.stdout = open("CHIAHET2.OUT", "w")

    data = sys.stdin.read().split()

    T = int(data[0])
    index = 1
    results = []

    for _ in range(T):
        N = int(data[index])
        X = int(data[index + 1])
        index += 2

        num = binpow(10, N) - 1
        num1 = binpow(10, N - 1) - 1
        results.append(F(num, X) - F(num1, X))

    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    main()