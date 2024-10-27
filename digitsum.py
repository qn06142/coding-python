T = int(input())  
for _ in range(T):

    data = list(map(int, input().split()))
    n = data[0]
    a = data[1:]

    a.sort()

    i = 0
    while a[i] == 0:  
        i += 1

    a[0], a[i] = a[i], a[0]

    if a[1] == 0:
        i += 1
        a[1], a[i] = a[i], a[1]

    A, B = 0, 0

    for i in range(n):
        if i % 2 == 0:
            A = A * 10 + a[i]
        else:
            B = B * 10 + a[i]

    print(A + B)