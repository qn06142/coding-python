for n in [int(input())]:
    for a1, a2 in [[int(i) for i in input().split()]]:
        print(a1 + (n - 1) * (a2 - a1), n * (2 * a1 + (n - 1) * (a2 - a1)) // 2, end = '\n')
