for i in range(0, int(input())):
    a, b = tuple(int(i) for i in input().split())
    print(pow(a, b, int(1e9 + 7)))