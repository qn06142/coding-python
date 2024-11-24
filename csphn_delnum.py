input()
a = [int(i) for i in input().split()]

while True:
    for i in range(1, len(a) - 1):
        if a[i] < a[i - 1] and a[i] < a[i + 1]:
            a.pop(i)
            break
    else:
        break
print(len(a))
