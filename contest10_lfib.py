fib = [0, 1, 1]
for i in range(0, 1000):
    fib.append(fib[-1] + fib[-2])
for _ in range(0, int(input())):
    i, j, s = (int(i) for i in input().split());
    print("YES" if fib[i] + fib[j] == s else "NO")