n, char = input().split()
n = int(n)
for _ in range(0, n):
    s = input()
    print(s if not any(char == i for i in s) else '')