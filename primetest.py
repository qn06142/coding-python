n = int(input())
factorial = [1]
for i in range(1,n+1):
    factorial.append(factorial[i-1]*i)
def calc(x):
    return (factorial[x] % (x + 1) // x) * (x - 1) + 2
count = [0 for i in range(n+1)]
for i in range(2, n):
    a = calc(i)
    if count[a] == 0:
        print(a)
        count[a] = 1
